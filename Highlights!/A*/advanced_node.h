//
// Created by Athan Johnson on 9/20/23.
//

#ifndef A__ADVANCED_NODE_H
#define A__ADVANCED_NODE_H

#include "dodecahedron.h"

class AdvancedNode {

public:
    AdvancedNode();

    AdvancedNode(const Dodecahedron&, std::string, int, int);

    bool operator>(const AdvancedNode&) const;

    bool is_solved() const;

    int get_cost();

    void print(const Dodecahedron&);

    std::array<AdvancedNode, 12> create_child_nodes(const Dodecahedron&);
    int m_depth;

private:
    bool m_is_solved;
    int m_cost_to_get_here;
    std::string m_rotations_performed;
};


#endif //A__ADVANCED_NODE_H
