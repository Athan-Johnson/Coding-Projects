//
// Created by Athan Johnson on 9/16/23.
//

#include "dodecahedron.h"

Dodecahedron::Dodecahedron() {

    // setup our m_faces array
    for (int color = 0; color < 12; color++) {
        m_faces[color] = std::make_shared<Face>(Face(Colors(color)));
    }

    // unfortunately this is just tedious
    m_colors_to_chars[white] = "Wh";
    m_colors_to_chars[yellow] = "Ye";
    m_colors_to_chars[dark_blue] = "DB";
    m_colors_to_chars[red] = "Re";
    m_colors_to_chars[dark_green] = "DG";
    m_colors_to_chars[purple] = "Pu";
    m_colors_to_chars[grey] = "Gr";
    m_colors_to_chars[beige] = "Be";
    m_colors_to_chars[light_blue] = "LB";
    m_colors_to_chars[orange] = "Or";
    m_colors_to_chars[light_green] = "LG";
    m_colors_to_chars[pink] = "Pi";

    // each face needs two parts to be complete, neighbor_faces and pieces_on_edge
    // this sets up neighbor faces which is needed to make pieces on edge
    for (auto f : m_faces) { // first we go through each face
        std::array<std::weak_ptr<Face>, Face::NEIGHBORS_PER_FACE> neighbor_array; // make the array of neighbors

        for (int i = 0; i < Face::NEIGHBORS_PER_FACE; i++) { // then we go through the faces neighbors
            neighbor_array[i] = m_faces[(Face::face_neighbors[f->m_color])[i]]; // we assign a weak pointer in the array to a neighbor
        }
        f->setup_neighbor_faces(neighbor_array);
    }

    // here is where we set up pieces on edge
    for (auto f: m_faces) { // start with a face

        std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> > future_face_map; // this will be pieces on edge soon

        std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> current_pieces; // these are the pieces that will be on the edge
        std::shared_ptr<Face> left_face;
        std::shared_ptr<Face> middle_face;
        std::shared_ptr<Face> right_face;

        for (int i = 0; i < Face::NEIGHBORS_PER_FACE; i++) { // now we go through each neighbor and look at their left and right
            left_face = m_faces[(Face::face_neighbors[f->m_color])[i]];
            middle_face = m_faces[(Face::face_neighbors[f->m_color])[(i + 1) % Face::NEIGHBORS_PER_FACE]]; // this clever mod trick allows us to wrap aroud back to zero nice and easy
            right_face = m_faces[(Face::face_neighbors[f->m_color])[(i + 2) % Face::NEIGHBORS_PER_FACE]];

            // make sets of the colors
            std::set<Colors> left_corner_piece_colors;
            std::set<Colors> edge_piece_colors;
            std::set<Colors> right_corner_piece_colors;

            left_corner_piece_colors.insert(f->m_color);
            left_corner_piece_colors.insert(left_face->m_color);
            left_corner_piece_colors.insert(middle_face->m_color);

            edge_piece_colors.insert(f->m_color);
            edge_piece_colors.insert(middle_face->m_color);

            right_corner_piece_colors.insert(f->m_color);
            right_corner_piece_colors.insert(right_face->m_color);
            right_corner_piece_colors.insert(middle_face->m_color);

            // if the piece doesn't exist yet, make it
            if (m_pieces.find(left_corner_piece_colors) == m_pieces.end()) { // try to make left corner
                Piece left_corner(left_corner_piece_colors);
                std::map<Colors, Colors> left_corners_map;
                for (auto c : left_corner_piece_colors) {
                    left_corners_map.insert(std::make_pair(c, c));
                }
                left_corner.setup_real_color_to_current_sticker(left_corners_map);
                m_pieces.insert(std::make_pair(left_corner_piece_colors, std::make_shared<Piece>(left_corner)));
            }
            if (m_pieces.find(edge_piece_colors) == m_pieces.end()) { // try to make middle edge
                Piece edge(edge_piece_colors);
                std::map<Colors, Colors> edge_map;
                for (auto c : edge_piece_colors) {
                    edge_map.insert(std::make_pair(c, c));
                }
                edge.setup_real_color_to_current_sticker(edge_map);
                m_pieces.insert(std::make_pair(edge_piece_colors, std::make_shared<Piece>(edge)));
            }
            if (m_pieces.find(right_corner_piece_colors) == m_pieces.end()) { // try to make right corner
                Piece right_corner(right_corner_piece_colors);
                std::map<Colors, Colors> right_corners_map;
                for (auto c : right_corner_piece_colors) {
                    right_corners_map.insert(std::make_pair(c, c));
                }
                right_corner.setup_real_color_to_current_sticker(right_corners_map);
                m_pieces.insert(std::make_pair(right_corner_piece_colors, std::make_shared<Piece>(right_corner)));
            }

            // access the pieces we've been using and put them into current pieces. This is the edge
            current_pieces[0] = m_pieces[left_corner_piece_colors];
            current_pieces[1] = m_pieces[edge_piece_colors];
            current_pieces[2] = m_pieces[right_corner_piece_colors];

            // put our edge inside a map where the face that neighbors f will return the edge we just made
            future_face_map.insert(std::make_pair(middle_face, current_pieces));
        }

        if (f->m_pieces_on_edge == nullptr) {
            f->setup_neighbor_pieces(std::make_shared<std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> > >(future_face_map));
        }

    }

    // SANITY CHECK THIS IS SUPER IMPORTANT
    for (auto f : m_faces) {
        for (auto c : Face::face_neighbors[f->m_color]) {
            for (int i = 0; i < Face::PIECES_PER_EDGE; i++) {

                std::shared_ptr<Piece> f_piece = ((*f->m_pieces_on_edge)[m_faces[c]])[i].lock();
                bool failure = true;

                for (int j = 0; j < Face::PIECES_PER_EDGE; j++) {
                    std::shared_ptr<Piece> other_piece = ((*m_faces[c]->m_pieces_on_edge)[f])[j].lock();
                    if (f_piece == other_piece) {
                        failure = false;
                    }
                }

                if (failure) {
                    std::cout << "AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
                    std::cout
                            << "Something is extremely wrong and you need to go in a corner and cry because that's the only way to fix this"
                            << std::endl;
                    std::cout << m_pieces.size() << std::endl;
                }
            }
        }
    }

    m_current_face = m_faces[white];
}

Dodecahedron::Dodecahedron(const Dodecahedron &other) {

    // setup our m_faces array
    for (int color = 0; color < 12; color++) {
        m_faces[color] = std::make_shared<Face>(Face(Colors(color)));
    }

    m_colors_to_chars[white] = "Wh";
    m_colors_to_chars[yellow] = "Ye";
    m_colors_to_chars[dark_blue] = "DB";
    m_colors_to_chars[red] = "Re";
    m_colors_to_chars[dark_green] = "DG";
    m_colors_to_chars[purple] = "Pu";
    m_colors_to_chars[grey] = "Gr";
    m_colors_to_chars[beige] = "Be";
    m_colors_to_chars[light_blue] = "LB";
    m_colors_to_chars[orange] = "Or";
    m_colors_to_chars[light_green] = "LG";
    m_colors_to_chars[pink] = "Pi";

    // copy pieces one by one
    for (auto p : other.m_pieces) {
        std::set<Colors> piece_colors;
        for (auto c : p.first) {
            piece_colors.insert(c);
        }
        std::shared_ptr<Piece> new_piece = std::make_shared<Piece>(piece_colors);
        new_piece->setup_real_color_to_current_sticker((p.second)->m_real_color_to_current_sticker);
        m_pieces.insert(std::make_pair(piece_colors, new_piece));
    }

    // this can just be copied from the original constructor
    for (auto f : m_faces) { // first we go through each face
        std::array<std::weak_ptr<Face>, Face::NEIGHBORS_PER_FACE> neighbor_array; // make the array of neighbors

        for (int i = 0; i < Face::NEIGHBORS_PER_FACE; i++) { // then we go through the faces neighbors
            neighbor_array[i] = m_faces[(Face::face_neighbors[f->m_color])[i]]; // we assign a weak pointer in the array to a neighbor
        }
        f->setup_neighbor_faces(neighbor_array);
    }

    // this is a little different from the original constructor
    for (auto f : m_faces) {
        std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> > future_face_map;

        std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> current_pieces;
        std::shared_ptr<Face> left_face;
        std::shared_ptr<Face> middle_face;
        std::shared_ptr<Face> right_face;
        for (int i = 0; i < Face::NEIGHBORS_PER_FACE; i++) {
            left_face = m_faces[(Face::face_neighbors[f->m_color])[i]];
            middle_face = m_faces[(Face::face_neighbors[f->m_color])[(i + 1) % Face::NEIGHBORS_PER_FACE]];
            right_face = m_faces[(Face::face_neighbors[f->m_color])[(i + 2) % Face::NEIGHBORS_PER_FACE]];

            std::set<Colors> left_corner_piece_colors;
            std::set<Colors> edge_piece_colors;
            std::set<Colors> right_corner_piece_colors;

            left_corner_piece_colors.insert(f->m_color);
            left_corner_piece_colors.insert(left_face->m_color);
            left_corner_piece_colors.insert(middle_face->m_color);

            edge_piece_colors.insert(f->m_color);
            edge_piece_colors.insert(middle_face->m_color);

            right_corner_piece_colors.insert(f->m_color);
            right_corner_piece_colors.insert(right_face->m_color);
            right_corner_piece_colors.insert(middle_face->m_color);

            // here is the difference, instead of making pieces we already have them.
            // So now we instead find the piece and build our variables
            current_pieces[0] = m_pieces[left_corner_piece_colors];
            current_pieces[1] = m_pieces[edge_piece_colors];
            current_pieces[2] = m_pieces[right_corner_piece_colors];

            future_face_map.insert(std::make_pair(middle_face, current_pieces));
        }

        if (f->m_pieces_on_edge == nullptr) {
            f->setup_neighbor_pieces(std::make_shared<std::map<std::shared_ptr<Face>, std::array<std::weak_ptr<Piece>, Face::PIECES_PER_EDGE> > >(future_face_map));
        }
    }

    // SANITY CHECK THIS IS SUPER IMPORTANT
    // making sure that my pointer shenanagins worked and two different faces actually map to the same pieces on their edge
    for (auto f : m_faces) {
        for (auto c : Face::face_neighbors[f->m_color]) {
            for (int i = 0; i < Face::PIECES_PER_EDGE; i++) {

                std::shared_ptr<Piece> f_piece = ((*f->m_pieces_on_edge)[m_faces[c]])[i].lock();
                bool failure = true;

                for (int j = 0; j < Face::PIECES_PER_EDGE; j++) {
                    std::shared_ptr<Piece> other_piece = ((*m_faces[c]->m_pieces_on_edge)[f])[j].lock();
                    if (f_piece == other_piece) {
                        failure = false;
                    }
                }

                if (failure) {
                    std::cout << "AHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHHH" << std::endl;
                    std::cout
                            << "Something is extremely wrong and you need to go in a corner and cry because that's the only way to fix this"
                            << std::endl;
                    std::cout << m_pieces.size() << std::endl;
                }
            }
        }
    }
    // more sanity checks: hunting for null pointers (there had better not be any)
    for (auto f : m_faces) {
        for (auto neighbors_weak_ptr : f->m_neighbor_faces) {
            if (neighbors_weak_ptr.expired()) {
                std::cout << "NOOOOOOOOOOOOOOOOOOOOOO" << std::endl;
            }
            else {
                std::shared_ptr<Face> neighbor = neighbors_weak_ptr.lock();
                for (auto pair : *neighbor->m_pieces_on_edge) {
                    for (auto piece_weak_ptr : pair.second) {
                        if (piece_weak_ptr.expired()) {
                            std::cout << "WHYYYYYYYYYYYYY" << std::endl;
                        }
                        else {
                            std::shared_ptr<Piece> piece = piece_weak_ptr.lock();
                            if (piece->m_colors_list.empty() || piece->m_real_color_to_current_sticker.empty()) {
                                std::cout << "the colors list is empty?!" << std::endl;
                            }
                        }
                    }
                }
            }
        }
    }

    m_current_face = other.m_current_face;
}

void Dodecahedron::print() {
    std::cout << std::endl;
    for (auto f : m_faces) {
        std::cout << m_colors_to_chars[f->m_color] << " face:" << std::endl;
        for (auto n : f->m_neighbor_faces) {
            std::shared_ptr<Face> neighbor = n.lock();
            std::cout << "  " << m_colors_to_chars[neighbor->m_color] << " Edge: ";
            for (auto p : (*(neighbor->m_pieces_on_edge))[f]) {
                std::shared_ptr<Piece> piece = p.lock();
                std::cout << m_colors_to_chars[(piece->m_real_color_to_current_sticker)[f->m_color]] << " ";
            }
        }
        std::cout << std::endl;
    }
}

// I think the rest of these functions are self explainatory
void Dodecahedron::change_face(int new_color) {
    if (new_color > 11  || new_color < 0) {
        std::cout << "Out of bounds face" << std::endl;
    }
    m_current_face = m_faces[new_color];
}

void Dodecahedron::rotate_clockwise() {
    m_current_face->rotate_clockwise();
}

void Dodecahedron::rotate_counter_clockwise() {
    m_current_face->rotate_counterclockwise();
}

void Dodecahedron::randomize(int num_rotations) {
    std::random_device rd;
    std::mt19937 gen(rd());
    int min = 0;
    int max = 11;

    std::uniform_int_distribution<int> distribution(min, max);

    for (int i = 0; i < num_rotations; i++) {
        change_face(distribution(gen));
        rotate_counter_clockwise();
    }
}

int Dodecahedron::get_dodec_heuristic() {
    int heuristic = 0;
    for (auto f : m_faces) {
        if (f->get_face_heuristic() > heuristic) {
            heuristic = f->get_face_heuristic();
        }
        else if (f->get_face_heuristic() == -1) {
            std::cout << "face heuristic is returning -1" << std::endl;
        }
    }
    return heuristic;
}