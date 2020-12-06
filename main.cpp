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
    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    std::vector<std::unique_ptr<instruccion>> instrucciones;
    try{
        std::cout<<"Analisis Lexico"<<std::endl;
        lexicalAnalyzer().analyze(pathg + "testFile3.txt", output, ids);
        for(auto &line:output){
            std::cout<<line.second<<' ';
            for(auto &word:line.first){
                std::cout<<" ["<<word<<"] ";
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
        std::cout<<"Analisis Sintactico"<<std::endl;
        sintacticAnalyzer().analyze(output, ids, instrucciones);

        std::cout <<"Iniciando ejecucion (analisis semantico):"<<std::endl;
        for(const auto& x : instrucciones)
        {
            x->ejecutar();
        }


    }
    catch(CompilationException &e){
        std::cout<<e.what()<<" in line "<<e.line()<<":\n"<<e.info();
    }
    catch(std::exception &e){
        std::cout<<"Error desconocido "<<e.what()<<std::endl;
    }
}
