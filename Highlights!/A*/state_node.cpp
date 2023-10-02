//
// Created by Athan Johnson on 9/17/23.
//

#include "state_node.h"

// Default constructor
StateNode::StateNode() : m_cost_to_get_here(std::numeric_limits<int>::max()), m_is_solved(false), m_depth(0) {}

// Parameterized constructor
StateNode::StateNode(Dodecahedron my_dodec, int parent_cost, int parent_depth) {
    // Initialize member variables
    m_dodec = my_dodec;
    m_cost_to_get_here = m_dodec.get_dodec_heuristic() + parent_cost;
    m_depth = parent_depth + 1;

    // Check if the heuristic is zero to determine if the state is solved
    if (my_dodec.get_dodec_heuristic() == 0) {
        m_is_solved = true;
    }
    else {
        m_is_solved = false;
    }
}

// Comparison operator to compare StateNodes based on cost
bool StateNode::operator>(const StateNode &other) const {
    if (m_cost_to_get_here > other.m_cost_to_get_here) {
        return true;
    }
    return false;
}

// Check if the state is solved
bool StateNode::is_solved() const {
    return m_is_solved;
}

// Get the cost to reach this state
int StateNode::get_cost() {
    return m_cost_to_get_here;
}

// Print the state's details
void StateNode::print() {
    m_dodec.print();
    std::cout << "Cost to get here: " << m_cost_to_get_here
        << "  Heuristic of this node: " << m_dodec.get_dodec_heuristic()
        << "  Depth in the tree: " << m_depth
        << std::endl << std::endl;
}

// Create child nodes by applying rotations to the current state
std::array<StateNode, 12> StateNode::create_child_nodes() {
    std::array<StateNode, 12> child_nodes;
    Dodecahedron temp_dodec = m_dodec;

    for (int i = 0; i < 12; i++) {
        // Apply a face change and rotation
        temp_dodec.change_face(i);
        temp_dodec.rotate_clockwise();
        // Create a new StateNode for the child and add it to the array
        child_nodes[i] = StateNode(temp_dodec, m_cost_to_get_here, m_depth);
        temp_dodec.rotate_counter_clockwise(); // Restore the original state
    }

    return child_nodes;
}
