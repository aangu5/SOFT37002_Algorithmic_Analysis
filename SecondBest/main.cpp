#include "SecondBest.cpp"
#include <iostream>

int main(int argc, char* argv[])
{
    // argv[0] is the program name, argv[1] is the input file name
    if (argc != 2) {
        std::cout << "Please add a filename into the command arguments. \nIf the filename contains spaces, please surround it with double quotes." << std::endl;
        return 1;
    }

    std::cout << SecondBest::solveTheWall(argv[1]);

    return 0;
}