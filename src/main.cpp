#include "util.h"
#include "lexicalAnalyzer.h"
#include "expressionEvaluator.h"
#include "sintacticAnalyzer.h"
#include "expresion.h"
#include "instruccion.h"

using namespace gm;

std::shared_ptr<tablaDeValores> table2(new tablaDeValores);
std::shared_ptr<tablaDeValores> expresion::table = table2;
std::shared_ptr<tablaDeValores> instruccion::table = table2;

int main(int argc, char* argv[]){
    std::string filename = "examples/saludo.txt";

    //Comentar estas lineas para que ignore los argumentos
    if(argc == 1){
        std::cerr << "Error: El archivo a compliar no fue proporcionado." << std::endl;
        exit(1);
    }
    if(argc > 3){
        std::cerr << "Error: Proporciono mas argumentos de los que se pueden procesar. Vuelva a intenarlo." << std::endl;
        exit(1);
    }
    if(argc == 3)Debug::debug = true;
    filename = std::string(argv[1]);
    //Termina de comentar

    tokenMatrix output;
    std::vector<std::vector<int>> ids;
    std::vector<std::unique_ptr<instruccion>> instrucciones;
    try{
        lexicalAnalyzer().analyze( filename, output, ids);

        if(Debug::debug){
            std::cout<<"Analisis Lexico"<<std::endl;
            std::cout<<"\nTokens:"<<std::endl;
            for(auto &line:output){
                std::cout<<line.second<<' ';
                for(auto &word:line.first){
                    std::cout<<" ["<<word<<"] ";
                }

                std::cout<<std::endl;
            }
            std::cout<<"\nIds:"<<std::endl;
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
        }
        sintacticAnalyzer().analyze(output, ids, instrucciones);

        if(Debug::debug)std::cout <<"Iniciando ejecucion (analisis semantico):"<<std::endl;
        for(const auto& x : instrucciones)
        {
            x->ejecutar();
        }


    }
    catch(CompilationException &e){
        if(e.line() == 0)
            std::cerr<<e.what()<<":\n"<<e.info();
        else
            std::cerr<<e.what()<<" en la linea "<<e.line()<<":\n"<<e.info();
    }
    catch(std::exception &e){
        std::cerr<<"Error desconocido "<<e.what()<<std::endl;
    }
}
