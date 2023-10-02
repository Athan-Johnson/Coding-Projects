//
// Created by Athan Johnson on 3/10/23.
//

#ifndef MINESWEEPER_TILEBUTTON_H
#define MINESWEEPER_TILEBUTTON_H

#include <QPushButton>
#include <QWidget>
#include <QMouseEvent>
#include "tile.h"

class TileButton : public QPushButton {
Q_OBJECT

public:

    explicit TileButton(QWidget* parent = nullptr);

signals:

    void rightClicked();

public slots:

    void updateIcon(std::shared_ptr<Tile> tile);

    void mouseReleaseEvent(QMouseEvent *event);

};


#endif //MINESWEEPER_TILEBUTTON_H
