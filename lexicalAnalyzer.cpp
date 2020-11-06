#include "lexicalAnalyzer.h"

#include <utility>

namespace gm{
    lexicalAnalyzer::lexicalAnalyzer(std::unique_ptr<std::ifstream> archivo, std::shared_ptr<std::unordered_map<std::string, int>> wordMap)
    : archivo_(std::move(archivo)), wordMap_(std::move(wordMap)) {}

    void lexicalAnalyzer::Read(std::vector<std::vector<std::string>>& tokens)
    {
        std::string partialRead;
        std::vector<std::string> splitLine;
        while(!(archivo_->eof()))
        {
            getline(*archivo_, partialRead);
            split(partialRead, splitLine);
            tokens.emplace_back(std::move(splitLine));
            splitLine.clear();
            partialRead.clear();
        }
    }

    bool check(std::vector<std::vector<std::string>> &tokens, std::vector<std::vector<int>> &keys){

    }

}
