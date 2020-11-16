#include "util.h"
#include "lexicalAnalyzer.h"

using namespace gm;

//Path for testing
const std::string path = "D:/TODO/Programas Weeb/proyecto-compilador/";

int main(){
    //Driver program to test the syntax analyzer
    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    lexicalAnalyzer().analyze(path+"testFile.txt", output, ids);
    for(auto &line:output){
        for(auto &word:line){
            std::cout<<'['<<word<<"] ";
        }
        std::cout<<std::endl;
    }

    for(const auto& line: ids)
    {
        for(auto id: line)
        {
            std::cout<<'['<<id<<"] ";
        }
        std::cout<<std::endl;
    }
}
