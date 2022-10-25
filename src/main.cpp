#include "solver.h"

#include <algorithm>
#include <iostream>

int main()
{
    std::vector<std::vector<unsigned>> data = {{1, 2, 3},
                                               {4, 5, 6},
                                               {7, 0, 8}};
    const auto board = Board(data);

    //// Uncomment top ^ and comment this line to solve custom board
//     const auto board = Board::create_random(4);

    const auto solution = Solver::solve(board);

    if (solution.moves() == 0 && Board::create_goal(board.size()) != board) {
        std::cout << "haha, try another board. This one isn't solvable";
    } else {
        std::cout << "The solution is " << solution.moves() << " moves";
        std::cout << "Let's take a closer look at them" << std::endl;
        std::cout << std::endl;
        for (const auto &move: solution) {
            std::cout << move << std::endl;
        }
        std::cout << "Those were all " << solution.moves() << " moves!";
    }
}
