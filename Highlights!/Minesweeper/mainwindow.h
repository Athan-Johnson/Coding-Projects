#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <vector>
#include <memory>
#include "tile.h"
#include "tilebutton.h"
#include <set>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:

    explicit MainWindow(QWidget* parent = nullptr);

    ~MainWindow() override;

private slots:

    static void quit();

    void sync();

    void shuffle();

    void connect_left_click(std::shared_ptr<Tile>);

    void connect_right_click(std::shared_ptr<Tile>);

    void update_statusbar();

    void find_tile_neighbors(std::shared_ptr<Tile>);

    void unblockButtonSignals();

    void tile_explored(std::shared_ptr<Tile>);

    void tile_reveal(std::shared_ptr<Tile>);

    void tile_flag_toggled(std::shared_ptr<Tile>);

    void mine_uncovered(std::shared_ptr<Tile>);

    void check_win();

private:
    unsigned m_num_flagged = 0;
    bool m_first_click = true;
    bool m_won = false;
    static const int GRID_SIZE = 16;
    static const int NUM_TILES = GRID_SIZE*GRID_SIZE;
    static const int NUM_MINES = 40;
    Ui::MainWindow* ui;
    std::array<std::shared_ptr<TileButton>, NUM_TILES> m_buttons;
    std::array<std::shared_ptr<Tile>, NUM_TILES> m_tiles;
    std::map<std::shared_ptr<Tile>, std::shared_ptr<TileButton>> m_buttonMap;
    std::set<std::shared_ptr<Tile>> m_unexplored;
    std::set<std::shared_ptr<Tile>> m_explored;
    std::set<std::shared_ptr<Tile>> m_mines;
    std::set<std::shared_ptr<Tile>> m_unflagged;
};

#endif // MAINWINDOW_H