#include "util.h"
#include "lexicalAnalyzer.h"
#include "expressionEvaluator.h"
#include "sintacticAnalyzer.h"
#include "expresion.h"
#include "instruccion.h"

using namespace gm;

//Path for testing
const std::string pathm = "D:/TODO/Programas Weeb/proyecto-compilador/";
const std::string pathg = "C:/users/ricar/documents/up/3/DSAII/3/proyecto-compilador/";

std::shared_ptr<tablaDeValores> table2(new tablaDeValores);
std::shared_ptr<tablaDeValores> expresion::table = table2;
std::shared_ptr<tablaDeValores> instruccion::table = table2;

int main(){
    //Driver program to test the syntax analyzer

    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    std::vector<std::unique_ptr<instruccion>> instrucciones;
    try{
        std::cout<<"Analisis Lexico"<<std::endl;
        lexicalAnalyzer().analyze(pathm+"testFile2.txt", output, ids);
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

        std::cout <<"Iniciando ejecucion:"<<std::endl;
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
    /*

    tokenMatrix output;
    std::shared_ptr<tablaDeValores> tabla;
    std::vector<std::vector<int>> ids;
    try{
        lexicalAnalyzer().analyze(pathm+"expressionsTest.txt", output, ids);
        for(auto &line:output){
            std::cout<<line.second;
            for(auto &word:line.first){
                std::cout<<" ["<<word<<"] ";
            }
            std::cout<<std::endl;
        }
        for(int i = 0;i<output.size();i++){
            std::cout<<expressionEvaluator().evaluate(ids[i],output[i].first,tabla)<<std::endl;
        }

    }
    catch(CompilationException &e){
        std::cout<<e.what()<<" in line "<<e.line()<<":\n"<<e.info();
    }
    catch(std::exception &e){
        std::cout<<"Unknown error "<<e.what()<<std::endl;
    }
 */
}
