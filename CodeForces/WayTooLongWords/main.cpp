/*
 * Input
 * The first line contains an integer n (1 ≤ n ≤ 100). Each of the following n lines contains one word.
 * All the words consist of lowercase Latin letters and possess the lengths of from 1 to 100 characters.
 *
 * Output
 * Print n lines. The i-th line should contain the result of replacing of the i-th word from the input data.
 */

#include <iostream>

int main() {

    int num_lines = 0;
    // first we recieve how many lines are going to be send
    std::cin >> num_lines;

    for (int i = 0; i < num_lines; i++) {
        std::string input, output;
        std::cin >> input;
        output = input;
        if (input.size() > 10) {
            output = input[0] + std::to_string(input.size() - 2) + input[input.size()-1];
        }
        std::cout << output << std::endl;
    }
}
