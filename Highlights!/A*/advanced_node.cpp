//
// Created by Athan Johnson on 9/20/23.
//

#include "advanced_node.h"

AdvancedNode::AdvancedNode() : m_cost_to_get_here(std::numeric_limits<int>::max()), m_is_solved(false), m_depth(0) {}

AdvancedNode::AdvancedNode(const Dodecahedron& starter_dodec, std::string my_rotations, int parent_cost, int parent_depth) {
    Dodecahedron temp_dodec = starter_dodec;
    m_rotations_performed = my_rotations;

    if (my_rotations != "empty") {
        for (auto c: my_rotations) {
            temp_dodec.change_face(c - '0');
            temp_dodec.rotate_clockwise();
        }
    }

    m_cost_to_get_here = temp_dodec.get_dodec_heuristic() + parent_cost;
    m_depth = parent_depth + 1;
    if (temp_dodec.get_dodec_heuristic() == 0) {
        m_is_solved = true;
    }
    else {
        m_is_solved = false;
    }
}

bool AdvancedNode::operator>(const AdvancedNode &other) const {
    if (m_cost_to_get_here > other.m_cost_to_get_here) {
        return true;
    }
    return false;
}

bool AdvancedNode::is_solved() const {
    return m_is_solved;
}

int AdvancedNode::get_cost() {

    return m_cost_to_get_here;
}

void AdvancedNode::print(const Dodecahedron& starter_dodec) {
    Dodecahedron temp_dodec = starter_dodec;
    if (m_rotations_performed != "empty") {
        for (auto c: m_rotations_performed) {
            temp_dodec.change_face(c - '0');
            temp_dodec.rotate_clockwise();
        }
    }

    temp_dodec.print();
    std::cout << "Cost to get here: " << m_cost_to_get_here
              << "  Heuristic of this node: " << temp_dodec.get_dodec_heuristic()
              << "  Depth in the tree: " << m_depth
              << std::endl << std::endl;
}

std::array<AdvancedNode, 12> AdvancedNode::create_child_nodes(const Dodecahedron& starter_dodec) {
    Dodecahedron temp_dodec = starter_dodec;
    if (m_rotations_performed != "empty") {
        for (auto c: m_rotations_performed) {
            temp_dodec.change_face(c - '0');
            temp_dodec.rotate_clockwise();
        }
    }
    else {
        m_rotations_performed = "";
    }

    std::array<AdvancedNode, 12> child_nodes;
    Dodecahedron temp_temp_dodec = temp_dodec;

    for (int i = 0; i < 12; i++) {
        temp_temp_dodec.change_face(i);
        temp_temp_dodec.rotate_clockwise();
        std::string temp_rotations = m_rotations_performed + char(i);
        child_nodes[i] = AdvancedNode(temp_dodec, temp_rotations, m_cost_to_get_here, m_depth);
        temp_dodec.rotate_counter_clockwise();
    }

    return child_nodes;
}
