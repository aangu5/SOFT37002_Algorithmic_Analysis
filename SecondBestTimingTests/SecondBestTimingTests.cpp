#include <iostream>
#include <chrono>
#include "../SecondBest/SecondBest.cpp"

using std::chrono::steady_clock;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

// https://stackoverflow.com/questions/5660527/how-do-i-return-a-char-array-from-a-function/5660589
char fileSeparator() {
#ifdef _WIN32
    return '\\';
#else 
    return '/';
#endif
}

nanoseconds calculateTiming(std::string filename) {
    steady_clock::time_point startTime = steady_clock::now();

    SecondBest::solveTheWall(filename);

    steady_clock::time_point finishTime = steady_clock::now();

    return duration_cast<nanoseconds>(finishTime - startTime);
}

int main()
{
    // Directory containing the test data as per the set provided on NOW
    std::string testFileDirectory = "C:\\temp\\Great_Wall_Problem-test_data\\";
    // Filename without the amount of bricks
    std::string testFileName = "input-pairs-{}.txt";

    // Swap these when testing the file locations
    std::string sizes[] = { "20", "50", "100", "200", "500", "1K", "2K", "5K", "10K", "20K", "50K", "100K", "200K", "500K", "1M", "2M", "3M" };
    //std::string sizes[] = { "20" };

    // Runs each file size through the algorithm and displays the timing
    // Does not print the results to the console to ensure optimum performance
    for (std::string size : sizes) {

        std::string filename = testFileName;
        filename.replace(testFileName.find_first_of("{"), 2, size);
        std::string fullPath = testFileDirectory + size + fileSeparator() + filename;

        nanoseconds timeTaken = calculateTiming(fullPath);

        std::cout << "Time Taken for " + size + ": " << timeTaken.count() << std::endl;
    }


}