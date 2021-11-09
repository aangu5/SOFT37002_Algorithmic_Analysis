#include "System.h"


bool System::checkFileExists(std::string filename)
{
    std::ifstream f(filename);
    return f.good();
}
