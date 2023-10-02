//
// Created by Athan Johnson on 3/10/23.
//

#ifndef MINESWEEPER_TILE_H
#define MINESWEEPER_TILE_H

#include <QObject>
#include <QIcon>
#include <QString>

class Tile : public QObject, public std::enable_shared_from_this<Tile> {
Q_OBJECT

public:

    enum Value {
    empty = 0, one, two, three, four, five, six, seven, eight, mine
};

    // Constructor
    explicit Tile(const QString& iconName, int x, int y);

    // update the icon
    [[nodiscard]] const QIcon& icon() const {
        static QIcon unexplored(":/unexplored.png");
        static QIcon flagged(":/flag.png");
        if (m_flagged) {
            return flagged;
        }
        else if (m_seen) {
            return m_shown;
        }
        return unexplored;
    }

    void increment_value();

    void clear();

    bool checked();

    Value m_value;
    int m_x, m_y;
    QIcon m_shown;
    bool m_seen, m_flagged, m_checked_since_shuffle;
    std::vector<std::shared_ptr<Tile>> neighbors;

public slots:

    void explore();

    void reveal_neighbors();

    void toggle_flag();

signals:

    void explored(std::shared_ptr<Tile>);

    void revealed_neighbors(std::shared_ptr<Tile>);

    void flag_toggled(std::shared_ptr<Tile>);

    void mine_hit(std::shared_ptr<Tile>);

};


#endif //MINESWEEPER_TILE_H
