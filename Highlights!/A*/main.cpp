

#include <iostream>
#include "dodecahedron.h"
#include "state_node.h"
#include <queue>
#include <cstdlib>
#include "advanced_node.h"

bool ADVANCED_NODES = true;
const int NUM_ROTATIONS = 2;

int main() {
    // An array to store the number of nodes visited for each iteration
    std::array<int, 5> nodes_visited;

    if (ADVANCED_NODES) {
        // Iterate five times
        for (int i = 0; i < 5; i++) {
            nodes_visited[i] = 0;
            std::string no_rotations = "empty";

            // Create a random Dodecahedron and perform random rotations
            Dodecahedron my_dec;
            my_dec.randomize(NUM_ROTATIONS);

            // Create an initial StateNode representing the current state
            AdvancedNode current_state(my_dec, no_rotations, 0, 0);

            // Create a min heap (priority queue) for A* search
            std::priority_queue<AdvancedNode, std::vector<AdvancedNode>, std::greater<AdvancedNode> > min_heap;
            min_heap.push(current_state);

            // Continue searching until the current state is solved
            while (!current_state.is_solved()) {
                // Get the state with the lowest cost from the priority queue
                current_state = min_heap.top();
                min_heap.pop();

                // Generate child nodes and add them to the priority queue
                std::array<AdvancedNode, 12> child_nodes = current_state.create_child_nodes(my_dec);
                for (auto child_node: child_nodes) {
                    min_heap.push(child_node);
                }

                // Print the current state and the number of nodes visited so far
                current_state.print(my_dec);
                nodes_visited[i]++;
                std::cout << "Number of nodes visited so far: " << nodes_visited[i] << std::endl << std::endl;
            }

            // Output the iteration number
            std::cout << "That was the " << i + 1 << "th iteration of A*.";
        }
    }
    else {
        // Iterate five times
        for (int i = 0; i < 5; i++) {
            nodes_visited[i] = 0;

            // Create a random Dodecahedron and perform random rotations
            Dodecahedron my_dec;
            my_dec.randomize(NUM_ROTATIONS);

            // Create an initial StateNode representing the current state
            StateNode current_state(my_dec, 0, 0);

            // Create a min heap (priority queue) for A* search
            std::priority_queue<StateNode, std::vector<StateNode>, std::greater<StateNode> > min_heap;
            min_heap.push(current_state);

            // Continue searching until the current state is solved
            while (!current_state.is_solved()) {
                // Get the state with the lowest cost from the priority queue
                current_state = min_heap.top();
                min_heap.pop();

                // Generate child nodes and add them to the priority queue
                std::array<StateNode, 12> child_nodes = current_state.create_child_nodes();
                for (auto child_node: child_nodes) {
                    min_heap.push(child_node);
                }

                // Print the current state and the number of nodes visited so far
                current_state.print();
                nodes_visited[i]++;
                std::cout << "Number of nodes visited so far: " << nodes_visited[i] << std::endl << std::endl;
            }

            // Output the iteration number
            std::cout << "That was the " << i + 1 << "th iteration of A*.";
        }
    }

    // Calculate and output the average number of nodes visited
    int avg = 0;
    for (auto num : nodes_visited) {
        avg += num;
    }
    avg = avg / 5;

    std::cout << std::endl << "The average number of nodes visited was: " << avg << std::endl;
}
