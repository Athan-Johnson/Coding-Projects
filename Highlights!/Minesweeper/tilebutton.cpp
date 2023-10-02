//
// Created by Athan Johnson on 3/10/23.
//

#include "tilebutton.h"

TileButton::TileButton(QWidget *parent) {
    parent = nullptr;
}

void TileButton::updateIcon(std::shared_ptr<Tile> tile) {
    setIcon(tile->icon());
}

void TileButton::mouseReleaseEvent(QMouseEvent *event) {
    if (event->button() == Qt::RightButton) {
        emit TileButton::rightClicked();
    }
    else {
        emit clicked();
    }
}
