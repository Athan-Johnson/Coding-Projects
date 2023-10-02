//
// Created by Athan Johnson on 9/16/23.
//

#ifndef MEGAMINX_2_0_FACE_H
#define MEGAMINX_2_0_FACE_H

#include "piece.h"
#include <iostream>
#include <map>
#include <cmath>


class Face {

public:

    Face(); // default constructor

    explicit Face(Colors);

    // member functions
    void setup_neighbor_faces(std::array<std::weak_ptr<Face>, 5>);

    void setup_neighbor_pieces(std::shared_ptr<std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, 3> > >);

    void rotate_clockwise();

    void rotate_counterclockwise();

    int get_face_heuristic();

    // member variables
    static std::array<std::array<Colors, 5>, 12> face_neighbors;
    Colors m_color;
    std::array<std::weak_ptr<Face>, 5> m_neighbor_faces;
    std::shared_ptr<std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, 3> > > m_pieces_on_edge;
    static const int NEIGHBORS_PER_FACE = 5;
    static const int PIECES_PER_EDGE = 3;
};


#endif //MEGAMINX_2_0_FACE_H
