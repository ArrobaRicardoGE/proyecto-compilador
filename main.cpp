#include "util.h"
#include "lexicalAnalyzer.h"
#include "expressionEvaluator.h"
#include "sintacticAnalyzer.h"

using namespace gm;

//Path for testing
const std::string pathm = "D:/TODO/Programas Weeb/proyecto-compilador/";
const std::string pathg = "C:/users/ricar/documents/up/3/DSAII/3/proyecto-compilador/";

int main(){
    //Driver program to test the syntax analyzer
    /*
    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    std::vector<std::unique_ptr<instruccion>> instrucciones;
    try{
        std::cout<<"Analisis Léxico"<<std::endl;
        lexicalAnalyzer().analyze(pathg+"testFile.txt", output, ids);
        for(auto &line:output){
            for(auto &word:line.first){
                std::cout<<line.second<<" ["<<word<<"] ";
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
        std::cout<<std::endl;
        std::cout<<"Analisis Semantico"<<std::endl;
        sintacticAnalyzer().analyze(output, ids, instrucciones);
        for(const auto& x : instrucciones)
        {
            x->ejecutar();
        }


    }
    catch(CompilationException &e){
        std::cout<<e.what()<<" in line "<<e.line()<<":\n"<<e.info();
    }
    catch(std::exception &e){
        std::cout<<"Unknown error "<<e.what()<<std::endl;
    }
    */
    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    try{
        lexicalAnalyzer().analyze(pathg+"expressionsTest.txt", output, ids);
        for(auto &line:output){
            std::cout<<line.second;
            for(auto &word:line.first){
                std::cout<<" ["<<word<<"] ";
            }
            std::cout<<std::endl;
        }
        for(int i = 0;i<output.size();i++){
            std::cout<<expressionEvaluator().evaluate(ids[i],output[i].first)<<std::endl;
        }

    }
    catch(CompilationException &e){
        std::cout<<e.what()<<" in line "<<e.line()<<":\n"<<e.info();
    }
    catch(std::exception &e){
        std::cout<<"Unknown error "<<e.what()<<std::endl;
    }

}
