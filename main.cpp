#include "util.h"
#include "lexicalAnalyzer.h"

using namespace gm;

//Path for testing
const std::string path = "D:/TODO/Programas Weeb/proyecto-compilador/";

int main(){
    //Driver program to test the syntax analyzer
    tokenMatrix output;
    vector<vector<int>> ids;
    lexicalAnalyzer().analyze(path+"testFile.txt", output, ids);
    for(auto &line:output){
        for(auto &word:line){
            std::cout<<'['<<word<<"] ";
        }
        std::cout<<std::endl;
    }
}
