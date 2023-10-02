//
// Created by Athan Johnson on 9/16/23.
//

#ifndef MEGAMINX_2_0_PIECE_H
#define MEGAMINX_2_0_PIECE_H

#include <set>
#include <memory>
#include <map>

enum Colors {white, yellow, dark_blue, red, dark_green, purple, grey,
    beige, light_blue, orange, light_green, pink, empty};

class Piece {

public:

    // default constructor
    Piece();

    // member variables
    std::set<Colors> m_colors_list;
    std::map<Colors, Colors> m_real_color_to_current_sticker;

    explicit Piece(std::set<Colors>); // Constructor

    // copy constructor
    Piece(const Piece&);

    // member functions
    void setup_real_color_to_current_sticker(std::map<Colors, Colors>);

    bool stickers_in_right_spots(Colors);

    void swap_corner_piece_stickers(Piece &, Colors);

    void swap_edge_piece_stickers(Piece &, Colors);
};


#endif //MEGAMINX_2_0_PIECE_H
