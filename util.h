#pragma once
#include <vector>
#include <iostream>
namespace gm {
    const char DELIMITER = ' ';

    void split(const std::string& s, std::vector<std::string>& answer, char delimiter = DELIMITER);

} //gm