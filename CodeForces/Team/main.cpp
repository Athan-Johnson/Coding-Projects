/*
 * Input
 * The first input line contains a single integer n (1≤n≤1000) — the number of problems in the contest.
 * Then n lines contain three integers each, each integer is either 0 or 1. If the first number in the
 * line equals 1, then Petya is sure about the problem's solution, otherwise he isn't sure. The second
 * number shows Vasya's view on the solution, the third number shows Tonya's view. The numbers on the
 * lines are separated by spaces.
 *
 * Output
 * Print a single integer — the number of problems the friends will implement on the contest.
 */

#include <iostream>

const int NUM_ON_TEAM = 3;

int main() {

    int num_problems = 0, output = 0, num_confident = 0;
    std::string input;

    std::cin >> num_problems;
    std::cin.ignore();

    for (int i = 0; i < num_problems; i++) {

        num_confident = 0;

        std::getline(std::cin, input);

        if (input.length() != NUM_ON_TEAM*2 - 1) {
            std::cout << "Wrong format! Input a valid line next time!" << std::endl;
        }
        else {
            for (int j = 0; j < NUM_ON_TEAM * 2 - 1; j+=2) { // this for loop skips the space each iteration
                if (input[j] == '1') {
                    num_confident++;
                }
            }
            if (num_confident > 1) {
                output++;
            }
        }
    }

    std::cout << output << std::endl;
    return 0;
}
