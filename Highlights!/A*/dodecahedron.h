//
// Created by Athan Johnson on 9/16/23.
//

#ifndef MEGAMINX_2_0_DODECAHEDRON_H
#define MEGAMINX_2_0_DODECAHEDRON_H

#include "face.h"
#include "piece.h"
#include <string>
#include <iostream>
#include <set>
#include <random>

class Dodecahedron {

public:
    Dodecahedron();

    // copy constructor
    Dodecahedron(const Dodecahedron &);

    // functions
    void print();

    void change_face(int);

    void rotate_clockwise();

    void rotate_counter_clockwise();

    void randomize(int);

    int get_dodec_heuristic();

private:
    std::array<std::shared_ptr<Face>, 12> m_faces;
    std::map<std::set<Colors>, std::shared_ptr<Piece> > m_pieces;
    std::map<Colors, std::string> m_colors_to_chars;
    std::shared_ptr<Face> m_current_face;

};

#endif //MEGAMINX_2_0_DODECAHEDRON_H
