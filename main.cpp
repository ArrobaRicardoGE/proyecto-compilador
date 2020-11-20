#include "util.h"
#include "lexicalAnalyzer.h"

using namespace gm;

//Path for testing
const std::string pathm = "D:/TODO/Programas Weeb/proyecto-compilador/";
const std::string pathg = "C:/users/ricar/documents/up/3/DSAII/3/proyecto-compilador/";

int main(){
    //Driver program to test the syntax analyzer
    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    try{
        lexicalAnalyzer().analyze(pathm+"testFile.txt", output, ids);
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
    catch(CompilationException &e){
        std::cout<<e.what()<<" in line "<<e.line()<<std::endl;
    }
    catch(std::exception &e){
        std::cout<<"Unknown exception "<<e.what()<<std::endl;
    }
}
