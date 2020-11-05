#pragma once
#include <vector>
#include <iostream>
namespace gm {
    const char DELIMITER = ' ';

    std::vector<std::string> split(const std::string& s, char delimiter = DELIMITER);

} //gm