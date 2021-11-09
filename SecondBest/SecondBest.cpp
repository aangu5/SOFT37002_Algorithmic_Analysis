#include <iostream>
#include <string>
#include <fstream>
#include <list>
#include <map>
#include <sstream>

class SecondBest {
    static bool checkFileExists(std::string filename)
    {
        std::ifstream f(filename);
        return f.good();
    }

public:
    static std::string solveTheWall(std::string filename) {
        std::cout << "Attempting to open file at: " << filename << "..." << std::endl;


        // Input validation that the file exists
        if (checkFileExists(filename)) {
            std::cout << "File opened successfully, starting programme." << std::endl;
        }
        else {
            std::cout << "Unable to open the file... Please check your programme arguments carefully." << std::endl;
            std::exit(1);
        }

        std::string line;
        std::ifstream filestream(filename);

        // One map to go east to west and one to go west to east
        std::map<std::string, std::string> bricksForwards;
        std::map<std::string, std::string> bricksBackwards;

        std::list<std::string> wall;
        std::pair<std::string, std::string> currentBrick;

        int commaIndex = 0;

        while (std::getline(filestream, line)) {

            // Using a logic block to avoid running temp.find_first_of(",") for each line
            if (!commaIndex)
                commaIndex = line.find_first_of(",");

            // Setting the variable within the loop to use the last item as the starting brick
            currentBrick = std::pair<std::string, std::string>(line.substr(0, commaIndex), line.substr(commaIndex + 1));

            bricksForwards.insert(currentBrick);

            // Creating a pair with the opposite direction for easy searching backwards
            std::pair<std::string, std::string> dataBackwards = std::pair<std::string, std::string>(currentBrick.second, currentBrick.first);
            bricksBackwards.insert(dataBackwards);
        }

        // Adding both elements of the starting brick to the wall
        wall.push_front(currentBrick.first);
        wall.push_back(currentBrick.second);

        // Searching to the east
        std::map<std::string, std::string>::const_iterator found = bricksForwards.find(currentBrick.second);

        while (found != bricksForwards.end()) {

            wall.push_back(found->second);

            found = bricksForwards.find(found->second);
        }

        // Searching to the west
        found = bricksBackwards.find(currentBrick.first);

        while (found != bricksBackwards.end()) {

            wall.push_front(found->second);

            found = bricksBackwards.find(found->second);
        }

        std::stringstream ss;

        // Displaying the final wall
        for (std::string brick : wall) {
            ss << brick << std::endl;
        }

        // Brick count for validation
        std::cout << "Amount of bricks: " << wall.size() << std::endl;

        return ss.str();
    }
};
