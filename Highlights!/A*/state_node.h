//
// Created by Athan Johnson on 9/17/23.
//

#ifndef A__STATE_NODE_H
#define A__STATE_NODE_H

#include "dodecahedron.h"
#include <iostream>
#include <limits>

class StateNode {

public:
    StateNode();

    StateNode(Dodecahedron, int, int);

    bool operator>(const StateNode&) const;

    bool is_solved() const;

    int get_cost();

    void print();

    std::array<StateNode, 12> create_child_nodes();
    int m_depth;

private:
    Dodecahedron m_dodec;
    bool m_is_solved;
    int m_cost_to_get_here;
};


#endif //A__STATE_NODE_H
