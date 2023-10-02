//
// Created by Athan Johnson on 3/10/23.
//

#include "tile.h"


Tile::Tile(const QString& iconName, int x, int y) : m_shown(iconName) {
    m_x = x;
    m_y = y;
    m_value = empty;
    m_seen = m_flagged = m_checked_since_shuffle = false;
}

void Tile::increment_value() {
    switch (m_value) {
        case empty :
            m_value = one;
            m_shown = QIcon(":/one.png");
            break;
        case one:
            m_value = two;
            m_shown = QIcon(":/two.png");
            break;
        case two:
            m_value = three;
            m_shown = QIcon(":/three.png");
            break;
        case three:
            m_value = four;
            m_shown = QIcon(":/four.png");
            break;
        case four:
            m_value = five;
            m_shown = QIcon(":/five.png");
            break;
        case five:
            m_value = six;
            m_shown = QIcon(":/six.png");
            break;
        case six:
            m_value = seven;
            m_shown = QIcon(":/seven.png");
            break;
        case seven:
            m_value = eight;
            m_shown = QIcon(":/eight.png");
            break;
        case eight:
            assert(false); // should never happen
            break;
        case mine: // two mines must be neighbors, just pretend nothing happened
            break;
    }
}

void Tile::clear() {
    if (m_value != mine) {
        m_value = empty;
        m_shown = QIcon(":/empty.png");
    }
    m_x = m_y = 0;
    m_checked_since_shuffle = false;
    neighbors.clear();
}

bool Tile::checked() {
    if (m_seen && m_checked_since_shuffle) {
        return true;
    }
    else {
        return false;
    }
}

void Tile::explore() {
    m_seen = m_checked_since_shuffle = true;
    if (m_value == mine) {
        emit(mine_hit(shared_from_this()));
    }
    emit(explored(shared_from_this()));
}

void Tile::reveal_neighbors() {
    int flagged_neighbors = 0;
    for (auto neighbor : neighbors) {
        if (neighbor->m_flagged) {
            flagged_neighbors++;
        }
    }
    if ((m_value == (Tile::Value)flagged_neighbors) || (m_value == empty)) {
        emit(revealed_neighbors(shared_from_this()));
    }
}

void Tile::toggle_flag() {
    m_flagged = !m_flagged;
    emit(flag_toggled(shared_from_this()));
}