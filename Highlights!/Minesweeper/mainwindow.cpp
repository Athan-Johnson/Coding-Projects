#include <cassert>
#include <algorithm>
#include <random>

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget* parent) :
        QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    const QSize TILE_SIZE(20, 20);
    const QSize ICON_SIZE(20, 20);
    this->setFixedSize(400, 500);
    ui->gridLayout->setSpacing(1);
    ui->gridLayout->setContentsMargins(0, 0, 0, 0);

    int index = 0;
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int column = 0; column < GRID_SIZE; ++column) {
            const QString tile_name =  ":/empty.png";

            auto tile = std::make_shared<Tile>(tile_name, row, column);
            m_tiles[index] = tile;
            m_unexplored.insert(tile);
            auto button = std::make_shared<TileButton>(this);
            m_buttons[index] = button;
            m_buttonMap[tile] = button;
            m_unflagged.insert(tile);

            button->setIcon(tile->icon());
            button->setIconSize(ICON_SIZE);
            button->setFixedSize(TILE_SIZE);
            button->setFlat(true);
            ui->gridLayout->addWidget(m_buttons[index].get(), row, column);

            // left click
            connect_left_click(tile);

            // right click
            connect_right_click(tile);

            // mine uncovered, by being clicked or passively uncovered by a tile that was improperly flagged being
            // clicked
            QObject::connect(tile.get(), SIGNAL(mine_hit(std::shared_ptr<Tile>)),
                             this, SLOT(mine_uncovered(std::shared_ptr<Tile>)));
            index++;
        }
    }

    assert(m_tiles[0].get() != nullptr);

    for (auto tile : m_tiles) {
        this->find_tile_neighbors(tile);
    }

    QObject::connect(ui->shuffleButton, SIGNAL(clicked()),
                     this, SLOT(shuffle()));
    QObject::connect(ui->quitButton, SIGNAL(clicked()),
                     this, SLOT(quit()));

    update_statusbar();
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::quit() {
    QApplication::quit();
}

void MainWindow::sync() {
    // synchronize the button icons with the cards
    for (auto& button: m_buttons) {
        button->disconnect(SIGNAL(clicked()));
        button->disconnect(SIGNAL(rightClicked()));
    }
    for (auto& tile: m_tiles){
        tile->disconnect(SIGNAL(explored(std::shared_ptr<Tile>)));
        tile->disconnect(SIGNAL(flag_toggled(std::shared_ptr<Tile>)));
        tile->disconnect(SIGNAL(revealed_neighbors(std::shared_ptr<Tile>)));
        tile->disconnect(SIGNAL(mine_hit(std::shared_ptr<Tile>)));
        tile->clear();
    }

    // tell all the tiles their new x and y
    int index = 0;
    for (int row = 0; row < GRID_SIZE; ++row) {
        for (int column = 0; column < GRID_SIZE; ++column) {
            m_tiles[index]->m_x = row;
            m_tiles[index]->m_y = column;
            index++;
        }
    }

    // fix button map
    m_buttonMap.clear();
    auto tileIt = m_tiles.begin();
    auto buttonIt = m_buttons.begin();
    while (tileIt != m_tiles.end()) {
        auto tile = *tileIt;
        auto button = *buttonIt;
        button->setIcon(tile->icon());
        m_buttonMap[tile] = button;
        ++tileIt;
        ++buttonIt;
    }

    assert(buttonIt == m_buttons.end());

    // re-estabilsh left click connection to unflagged tiles
    auto tileIt2 = m_unflagged.begin();
    while (tileIt2 != m_unflagged.end()) {
        auto tile = *tileIt2;
        connect_left_click(tile);
        tileIt2++;
    }

    // re-establish right click connection to unexplored tiles
    auto tileIt3 = m_unexplored.begin();
    while (tileIt3 != m_unexplored.end()) {
        auto tile = *tileIt3;
        auto button = m_buttonMap[tile];
        connect_right_click(tile);
        tileIt3++;
    }

    for (auto tile : m_tiles) {
        this->find_tile_neighbors(tile);
    }

    // allow all explored tiles to reveal neighbors
    for (auto tile : m_explored) {
        auto button = m_buttonMap[tile];
        button->disconnect(SIGNAL(rightClicked()));
        button->disconnect(SIGNAL(clicked()));
        QObject::connect(button.get(), SIGNAL(clicked()),
                         tile.get(), SLOT(reveal_neighbors()));
    }

    // reestablish this to all tiles
    for (auto tile : m_tiles) {
        QObject::connect(tile.get(), SIGNAL(mine_hit(std::shared_ptr<Tile>)),
                         this, SLOT(mine_uncovered(std::shared_ptr<Tile>)));
    }

    for (auto mine : m_mines) {
        for (auto neighbor : mine->neighbors) {
            neighbor->increment_value();
        }
    }

    for (auto tile : m_tiles) {
        m_buttonMap[tile]->updateIcon(tile);
    }

    update_statusbar();

    MainWindow::unblockButtonSignals();
}

void MainWindow::shuffle() {
    static std::default_random_engine generator;
    std::shuffle(m_tiles.begin(), m_tiles.end(), generator);

    MainWindow::sync();

}

void MainWindow::connect_left_click(std::shared_ptr<Tile> tile) {
    auto button = m_buttonMap[tile];
    QObject::connect(tile.get(), SIGNAL(explored(std::shared_ptr<Tile>)),
                     button.get(), SLOT(updateIcon(std::shared_ptr<Tile>)));
    QObject::connect(tile.get(), SIGNAL(revealed_neighbors(std::shared_ptr<Tile>)),
                     this, SLOT(tile_reveal(std::shared_ptr<Tile>)));
    QObject::connect(tile.get(), SIGNAL(explored(std::shared_ptr<Tile>)),
                     this, SLOT(tile_explored(std::shared_ptr<Tile>)));
    QObject::connect(button.get(), SIGNAL(clicked()),
                     tile.get(), SLOT(explore()));
}

void MainWindow::connect_right_click(std::shared_ptr<Tile> tile) {
    auto button = m_buttonMap[tile];
    QObject::connect(tile.get(), SIGNAL(flag_toggled(std::shared_ptr<Tile>)),
                     button.get(), SLOT(updateIcon(std::shared_ptr<Tile>)));
    QObject::connect(tile.get(), SIGNAL(flag_toggled(std::shared_ptr<Tile>)),
                     this, SLOT(tile_flag_toggled(std::shared_ptr<Tile>)));
    QObject::connect(button.get(), SIGNAL(rightClicked()),
                     tile.get(), SLOT(toggle_flag()));
}

void MainWindow::update_statusbar() {
    QString string = QString("Flags: " + QString::number(m_num_flagged) + "/" + QString::number(NUM_MINES));
    string += QString("    Cleared: " + QString::number(m_explored.size()) + "/" + QString::number(NUM_TILES-NUM_MINES));
    ui->statusBar->showMessage(string);
}

void MainWindow::find_tile_neighbors(std::shared_ptr<Tile> tile) {
    for (int row_offset = -1; row_offset <= 1; row_offset++) {
        for (int column_offset = -1; column_offset <= 1; column_offset++) {
            if ((row_offset != 0) || (column_offset != 0)) {
                int neighbor_x = tile->m_x + row_offset;
                int neighbor_y = tile->m_y + column_offset;
                bool x_in_bounds = (neighbor_x >= 0) && (neighbor_x < GRID_SIZE);
                bool y_in_bounds = (neighbor_y >= 0) && (neighbor_y < GRID_SIZE);
                if (x_in_bounds && y_in_bounds) {
                    auto neighbor = m_tiles[neighbor_x*GRID_SIZE + neighbor_y];
                    tile->neighbors.push_back(neighbor);
                }
            }
        }
    }
}

void MainWindow::unblockButtonSignals() {
    for (auto& tile : m_tiles) {
        assert(m_buttonMap[tile] != nullptr);
        tile->blockSignals(false);
        m_buttonMap[tile]->blockSignals(false);
        assert(!tile->signalsBlocked());
        assert(!m_buttonMap[tile]->signalsBlocked());
    }
    ui->shuffleButton->blockSignals(false);
    ui->quitButton->blockSignals(false);
}

void MainWindow::tile_explored(std::shared_ptr<Tile> tile) {

    // fix the right and left click
    auto button = std::make_shared<TileButton>(this);
    button = m_buttonMap[tile];
    button->disconnect(SIGNAL(rightClicked()));
    button->disconnect(SIGNAL(clicked()));
    QObject::connect(button.get(), SIGNAL(clicked()),
                     tile.get(), SLOT(reveal_neighbors()));

    // correct member variables
    m_unexplored.erase(tile);
    m_explored.insert(tile);

    // sets up all the mines on the board
    if (m_first_click) {
        m_first_click = false;

        for (int i = 0; i < NUM_MINES; i++) {
            int mine_x = (std::rand()) % GRID_SIZE;
            int mine_y = (std::rand()) % GRID_SIZE;
            bool new_x = mine_x != tile->m_x;
            bool new_y = mine_y != tile->m_y;
            bool not_prev_mine = m_tiles[mine_x*GRID_SIZE + mine_y]->m_value != Tile::mine;
            if (new_x && new_y && not_prev_mine) {
                auto mine = m_tiles[mine_x*GRID_SIZE + mine_y];
                mine->m_value = Tile::mine;
                mine->m_shown = QIcon(":/mine.png");
                for (auto neighbor : mine->neighbors) {
                    neighbor->increment_value();
                }
                m_mines.insert(mine);
            }
            else {
                i--;
            }
        }

        m_buttonMap[tile]->updateIcon(tile);
        assert(m_mines.size() == NUM_MINES);
    }

    if (tile->m_value == Tile::empty) {
        tile_reveal(tile);
    }

    // status bar
    update_statusbar();

    check_win();

}

void MainWindow::tile_reveal(std::shared_ptr<Tile> tile) {
    for (auto neighbor : tile->neighbors) {
        if (!(neighbor->m_flagged) && !(neighbor->checked())) {
            neighbor->explore();
            if (neighbor->m_value == Tile::empty) {
                tile_reveal(neighbor);
            }
        }
    }
}

void MainWindow::tile_flag_toggled(std::shared_ptr<Tile> tile) {

    // fix the right and left click and correct member variables
    auto button = std::make_shared<TileButton>(this);
    button = m_buttonMap[tile];
    if (tile->m_flagged) {
        button->disconnect(SIGNAL(clicked()));
        m_num_flagged++;
        m_unflagged.erase(tile);
    }
    else {
        button->disconnect(SIGNAL(clicked()));
        connect_left_click(tile);
        m_num_flagged--;
        m_unflagged.insert(tile);
    }

    // status bar
    update_statusbar();
}

void MainWindow::mine_uncovered(std::shared_ptr<Tile>) {
    for (auto mine : m_mines) {
        mine->m_flagged = false;
        mine->m_seen = true;
        m_buttonMap[mine]->updateIcon(mine);
    }

    for (auto tile : m_tiles) {
        tile->disconnect();
    }
    for (auto button : m_buttons) {
        button->disconnect();
    }

    QMessageBox::information(this, "Minesweeper", QString("You have lost the game!"));
}

void MainWindow::check_win() {
    if (!(m_won)) {
        if (m_explored.size() == NUM_TILES - NUM_MINES) {
            bool explored_correctly = true;
            for (auto tile_explored: m_explored) {
                if (tile_explored->m_flagged) {
                    explored_correctly = false;
                }
            }
            if (explored_correctly) {
                for (auto tile_dis: m_tiles) {
                    tile_dis->disconnect();
                }
                for (auto button_dis: m_buttons) {
                    button_dis->disconnect();
                }
                m_won = true;

                QMessageBox::information(this, "Minesweeper", QString("You have won the game!"));
            }
        }
    }
}

