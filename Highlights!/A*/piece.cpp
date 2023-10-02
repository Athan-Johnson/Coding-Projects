//
// Created by Athan Johnson on 9/16/23.
//

#include "piece.h"

Piece::Piece() = default;

Piece::Piece(std::set<Colors> colors) {
    for (auto c : colors) {
        m_colors_list.insert(c);
    }
}

Piece::Piece(const Piece &other) {
    for (auto c : other.m_colors_list) {
        m_colors_list.insert(c);
    }
    for (auto p : other.m_real_color_to_current_sticker) {
        m_real_color_to_current_sticker.insert(std::make_pair(p.first, p.second));
    }
}

void Piece::setup_real_color_to_current_sticker(std::map<Colors, Colors> map) {
    m_real_color_to_current_sticker = std::move(map);
}

bool Piece::stickers_in_right_spots(Colors color) {
    if (m_real_color_to_current_sticker[color] != color) {
        return false;
    }
    return true;
}

// when swapping two pieces' stickers we assume they are on the same edge.
// this means that both corners have one color that's the "central" one that is the same on each,
// and one on the left and right. The values in each map switch but the keys they're tied
// to remain the same. Excluding the central one, one of these keys both corners have,
// but one has it on the left and the other on the right
void Piece::swap_corner_piece_stickers(Piece &other, Colors stationary_face) {
    Colors same_color, my_diff_color, other_diff_color;
    for (auto my_c : m_colors_list) {
        for (auto other_c : other.m_colors_list) {
            if (my_c != stationary_face) {
                if (my_c == other_c) {
                    same_color = my_c;
                }
            }
        }
    }

    for (auto my_c : m_colors_list) {
        if ((my_c != stationary_face) && (my_c != same_color)) {
            my_diff_color = my_c;
        }
    }
    for (auto other_c : other.m_colors_list) {
        if ((other_c != stationary_face) && (other_c != same_color)) {
            other_diff_color = other_c;
        }
    }

    std::swap(m_real_color_to_current_sticker[stationary_face], other.m_real_color_to_current_sticker[stationary_face]);
    std::swap(m_real_color_to_current_sticker[my_diff_color], other.m_real_color_to_current_sticker[same_color]);
    std::swap(m_real_color_to_current_sticker[same_color], other.m_real_color_to_current_sticker[other_diff_color]);
}

// this is simpler, they both have the sationary color and the other color. It makes it all rather intuitive really
void Piece::swap_edge_piece_stickers(Piece &other, Colors stationary_face) {
    Colors my_diff_color, other_diff_color;
    for (auto my_c : m_colors_list) {
        if (my_c != stationary_face) {
            my_diff_color = my_c;
        }
    }
    for (auto other_c : other.m_colors_list) {
        if (other_c != stationary_face) {
            other_diff_color = other_c;
        }
    }

    std::swap(m_real_color_to_current_sticker[stationary_face], other.m_real_color_to_current_sticker[stationary_face]);
    std::swap(m_real_color_to_current_sticker[my_diff_color], other.m_real_color_to_current_sticker[other_diff_color]);
}