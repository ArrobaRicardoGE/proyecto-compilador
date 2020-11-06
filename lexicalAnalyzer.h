#pragma once

#include <fstream>
#include "util.h"

namespace gm {
    class lexicalAnalyzer {
    public:
        lexicalAnalyzer(std::unique_ptr<std::ifstream> archivo,
                        std::shared_ptr<std::unordered_map<std::string, int>> wordMap);

        void Read(std::vector<std::vector<std::string>> &tokens);

        bool check(std::vector<std::vector<std::string>> &tokens, std::vector<std::vector<int>> &keys);

    private:
        bool checkIntegerValue(std::string &possibleInteger);

        bool checkFloatValue(std::string &possibleFloat);

        std::shared_ptr<std::unordered_map<std::string, int>> wordMap_;
        std::vector<std::pair<int, int>> badLines_;
        std::unique_ptr<std::ifstream> archivo_;
    };
} //gm
