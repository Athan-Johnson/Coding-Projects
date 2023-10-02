//
// Created by Athan Johnson on 9/16/23.
//

#include "face.h"

#include <utility>

// I need to make all these arrays because clang and g++ are mad at me otherwise...


std::array<std::array<Colors, Face::NEIGHBORS_PER_FACE>, 12> Face::face_neighbors = {{
        {Colors::yellow, Colors::dark_blue, Colors::red, Colors::dark_green, Colors::purple},
         {Colors::dark_blue, Colors::white, Colors::purple, Colors::orange, Colors::light_green},
         {Colors::white, Colors::yellow, Colors::light_green, Colors::pink, Colors::red},
         {Colors::white, Colors::dark_blue, Colors::pink, Colors::beige, Colors::dark_green},
         {Colors::white, Colors::red, Colors::beige, Colors::light_blue, Colors::purple},
         {Colors::orange, Colors::yellow, Colors::white, Colors::dark_green, Colors::light_blue},
         {Colors::orange, Colors::light_blue, Colors::beige, Colors::pink, Colors::light_green},
         {Colors::dark_green, Colors::red, Colors::pink, Colors::grey, Colors::light_blue},
         {Colors::purple, Colors::dark_green, Colors::beige, Colors::grey, Colors::orange},
         {Colors::yellow, Colors::purple, Colors::light_blue, Colors::grey, Colors::light_green},
         {Colors::yellow, Colors::orange, Colors::grey, Colors::pink, Colors::dark_blue},
         {Colors::red, Colors::dark_blue, Colors::light_green, Colors::grey, Colors::beige},
        }};



Face::Face() {
    m_color = empty;
    m_pieces_on_edge = nullptr;
}

Face::Face(Colors color) {
    m_color = color;
    m_pieces_on_edge = nullptr;
}

void Face::setup_neighbor_faces(std::array<std::weak_ptr<Face>, Face::NEIGHBORS_PER_FACE> neighbor_faces) {
    m_neighbor_faces = std::move(neighbor_faces);
}

void Face::setup_neighbor_pieces(std::shared_ptr<std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> > > neighbor_pieces) {
    m_pieces_on_edge = std::move(neighbor_pieces);
}

void Face::rotate_clockwise() {
    // this code moves the stickers that are on the corners
    for (int i = NEIGHBORS_PER_FACE-1; i > 0; i--) { // swap the corners in a counter clockwise motion

        std::shared_ptr<Face> current_face = m_neighbor_faces[i].lock();
        std::shared_ptr<Piece> current_face_piece = ((*m_pieces_on_edge)[current_face])[0].lock();
        std::shared_ptr<Piece> current_face_piece_other = ((*m_pieces_on_edge)[current_face])[2].lock();

        current_face_piece->swap_corner_piece_stickers(*current_face_piece_other, m_color);
    }

    // this moves the stickers that are on the edges
    std::shared_ptr<Face> last_face = m_neighbor_faces[0].lock();
    for (int i = 1; i < NEIGHBORS_PER_FACE; i++) { // swap the edges in a clockwise motion.

        std::shared_ptr<Face> current_face = m_neighbor_faces[i].lock();
        std::shared_ptr<Piece> current_face_piece = ((*m_pieces_on_edge)[current_face])[1].lock();
        std::shared_ptr<Piece> last_face_piece = ((*m_pieces_on_edge)[last_face])[1].lock();

        current_face_piece->swap_edge_piece_stickers(*last_face_piece, m_color);
    }
}

// the rotations here just move stickers around
void Face::rotate_counterclockwise() {
    // this code moves the stickers that are on the corners
    for (int i = 1; i < NEIGHBORS_PER_FACE; i++) { // swap the corners in a counter clockwise motion

        std::shared_ptr<Face> current_face = m_neighbor_faces[i].lock();
        std::shared_ptr<Piece> current_face_piece = ((*m_pieces_on_edge)[current_face])[0].lock();
        std::shared_ptr<Piece> current_face_piece_other = ((*m_pieces_on_edge)[current_face])[2].lock();

        current_face_piece->swap_corner_piece_stickers(*current_face_piece_other, m_color);
    }

    // this moves the stickers that are on the edges
    std::shared_ptr<Face> last_face = m_neighbor_faces[0].lock();
    for (int i = NEIGHBORS_PER_FACE-1; i > 0; i--) { // swap the edges in a clockwise motion.

        std::shared_ptr<Face> current_face = m_neighbor_faces[i].lock();
        std::shared_ptr<Piece> current_face_piece = ((*m_pieces_on_edge)[current_face])[1].lock();
        std::shared_ptr<Piece> last_face_piece = ((*m_pieces_on_edge)[last_face])[1].lock();

        current_face_piece->swap_edge_piece_stickers(*last_face_piece, m_color);
    }
}

// logik: one rotation moves one edge and two corner pieces right? Sooooo if on a given face we have four edges wrong
// that means we need four moves MINIMUM to get all the pieces back where they belong
// The corners are moved two at a time so it takes ceil(corners_wrong/2) moves to fix them minimum
int Face::get_face_heuristic() {
    int corner_pieces_wrong = 0;
    int edge_pieces_wrong = 0;
    std::set<std::shared_ptr<Piece> > checked_corners; // this code checks each corner twice so we need to make sure we don't count it twice

    for (int i = 0; i < NEIGHBORS_PER_FACE; i++) {

        std::shared_ptr<Face> current_face = m_neighbor_faces[i].lock();

        for (int j = 0; j < Face::PIECES_PER_EDGE; j++) {

            std::shared_ptr<Piece> current_face_piece = ((*m_pieces_on_edge)[current_face])[j].lock();

            auto it = checked_corners.find(current_face_piece);
            if (!current_face_piece->stickers_in_right_spots(this->m_color)) {
                if (current_face_piece->m_colors_list.size() == 3) { // it's a corner piece
                    if ((it == checked_corners.end())) { // it's also one we haven't seen before
                        corner_pieces_wrong++;
                    }
                }
                else if (current_face_piece->m_colors_list.size() == 2) { // it's an edge piece
                    edge_pieces_wrong++;
                }
                else { // ?!?!?!?!?!
                    return -1;
                }
            }
            checked_corners.insert(current_face_piece);
        }
    }

    // almost done with a face, now we just get the heuristic and leave
    if (edge_pieces_wrong > ceil(corner_pieces_wrong/2)) {
        return edge_pieces_wrong;
    }
    else {
        return ceil(corner_pieces_wrong/2);
    }
}
