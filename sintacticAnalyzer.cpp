#include <memory>
#include "sintacticAnalyzer.h"
#include "asignar.h"
#include "expresionMatematica.h"
#include "read.h"
#include "declarar.h"
#include "print.h"
#include "ciclo.h"
#include "cicloFor.h"
#include "ifElse.h"

namespace gm{
    void sintacticAnalyzer::analyze(gm::tokenMatrix &tokens, std::vector<std::vector<int>>& ids,
                                    std::vector<std::unique_ptr<instruccion>>& arbolSintactico) {
        int a = analyzeToBracket(tokens, ids, arbolSintactico, 0);
        if(a != ids.size()){
            //std::cout<<"Error sintactico en linea "<<tokens[a-1].second<<std::endl;
            throw CompilationException("Error sintactio",tokens[a-1].second);
        }
    }

    int sintacticAnalyzer::analyzeToBracket(gm::tokenMatrix &tokens, std::vector<std::vector<int>>& ids,
                                            std::vector<std::unique_ptr<instruccion>>& arbolParcial, int index) {
        int i;
        for(i=index; i < ids.size(); i++)
        {

            if(ids[i][0] == '}') return i+1;
            if(ids[i][0] == VARIABLE && ids[i][1] == ASIGNAR && ids[i][2] != READ)
            {
                std::vector<std::string> tokensExpresion;
                std::vector<int> idsExpresion;
                copia(i,2,ids[i].size(),tokens, tokensExpresion);
                copiaIds(i,2,ids[i].size(),ids,idsExpresion);

                std::unique_ptr<expresionMatematica> evaluable(new expresionMatematica(std::move(tokensExpresion),std::move(idsExpresion)));
                arbolParcial.emplace_back(std::unique_ptr<asignar>(new asignar(tokens[i].first[0],std::move(evaluable)))); //remplazar con make_unique en c++14
            }
            else if(ids[i][0] == VARIABLE && ids[i][1] == ASIGNAR && ids[i][2] == READ){
                std::vector<std::string> vacio;
                std::vector<int> vacioIds;
                std::unique_ptr<read> lectura(new read(std::move(vacio), std::move(vacioIds)));
                arbolParcial.emplace_back(std::unique_ptr<asignar>(new asignar(tokens[i].first[0], std::move(lectura))));
            }
            else if(ids[i][0] >= 200 && ids[i][0] < 300 && ids[i][1] == VARIABLE && ids[i][2] == ASIGNAR){
                std::vector<std::string> tokensExpresion;
                std::vector<int> idsExpresion;
                if(ids[i][3] == READ)
                {
                    std::unique_ptr<read> lectura(new read(std::move(tokensExpresion), std::move(idsExpresion)));
                    std::unique_ptr<asignar> asignacion(new asignar(tokens[i].first[1], std::move(lectura)));
                    arbolParcial.emplace_back(std::unique_ptr<declarar>(new declarar(ids[i][0], std::move(asignacion))));
                }
                else{
                    copia(i, 3, ids[i].size(), tokens, tokensExpresion);
                    copiaIds(i,3,ids[i].size(), ids, idsExpresion);
                    std::unique_ptr<expresionMatematica> evaluable(new expresionMatematica(std::move(tokensExpresion), std::move(idsExpresion)));
                    std::unique_ptr<asignar> asignacion(new asignar(tokens[i].first[1], std::move(evaluable)));
                    arbolParcial.emplace_back(std::unique_ptr<declarar>(new declarar(ids[i][0], std::move(asignacion))));

                }
            }
            else if(ids[i][0] == PRINT && ids[i].size()>=4)
            {
                std::vector<std::string> tokensExpresion;
                std::vector<int> idsExpresion;
                copia(i, 2, ids[i].size()-1, tokens, tokensExpresion);
                copiaIds(i,2,ids[i].size()-1, ids, idsExpresion);
                std::unique_ptr<expresionMatematica> evaluable(new expresionMatematica(std::move(tokensExpresion), std::move(idsExpresion)));
                arbolParcial.emplace_back(std::unique_ptr<print>(new print(std::move(evaluable))));
            }
            else if(ids[i][0] == WHILE && ids[i][ids[i].size()-1] == '{')
            {
                std::vector<std::string> tokensExpresion;
                std::vector<int> idsExpresion;
                copia(i,1,ids[i].size()-1, tokens, tokensExpresion);
                copiaIds(i,1,ids[i].size() -1, ids, idsExpresion);
                std::unique_ptr<expresionMatematica> evaluable(new expresionMatematica(std::move(tokensExpresion), std::move(idsExpresion)));
                std::vector<std::unique_ptr<instruccion>> instruccionesEnCiclo;
                i = analyzeToBracket(tokens, ids, instruccionesEnCiclo, i+1);
                i--;
                arbolParcial.emplace_back(std::unique_ptr<ciclo>(new ciclo(std::move(evaluable), std::move(instruccionesEnCiclo))));
            }
            else if(ids[i][0] == FOR && ids[i][ids[i].size()-1] == '{')
            {
                int j;
                for(j = 1;j<ids[i].size();j++)
                {
                    if(ids[i][j] == TO) break;
                }
                if(j != ids[i].size() && ids[i][1] == VARIABLE && ids[i][2] == ASIGNAR && j>3)
                {
                    std::vector<std::string> tokensExpresion1;
                    std::vector<int> idsExpresion1;
                    std::vector<int> idsExpresion2;
                    std::vector<std::string> tokensExpresion2;
                    std::string variable = tokens[i].first[1];
                    copia(i,3, j,tokens, tokensExpresion1);
                    copiaIds(i,3,j, ids, idsExpresion1);
                    copia(i, j+1, ids[i].size()-1, tokens, tokensExpresion2);
                    copiaIds(i,j+1,ids[i].size()-1, ids, idsExpresion2);
                    std::unique_ptr<expresionMatematica> exp1(new expresionMatematica(std::move(tokensExpresion1), std::move(idsExpresion1)));
                    std::unique_ptr<expresionMatematica> exp2(new expresionMatematica(std::move(tokensExpresion2), std::move(idsExpresion2)));
                    std::unique_ptr<asignar> asignacion(new asignar(variable,std::move(exp1)));
                    std::vector<std::unique_ptr<instruccion>> instruccionesEnCiclo;
                    i  = analyzeToBracket(tokens, ids, instruccionesEnCiclo, i+1);
                    i -= 1;

                    arbolParcial.emplace_back(std::unique_ptr<cicloFor>(new cicloFor(std::move(asignacion), std::move(exp2), std::move(instruccionesEnCiclo), variable)));

                }
                else{
                    throw(CompilationException("Error sintactico en declaracion de ciclo For", tokens[i].second));
                }
            }
            else if(ids[i][0] == IF && ids[i][ids[i].size()-1] == '{')
            {
                std::vector<std::string> tokensExpresion;
                std::vector<int> idsExpresion;
                copia(i, 1, ids[i].size()-1, tokens, tokensExpresion);
                copiaIds(i, 1, ids[i].size()-1, ids, idsExpresion);
                std::unique_ptr<expresionMatematica> exp(new expresionMatematica(std::move(tokensExpresion), std::move(idsExpresion)));
                std::vector<std::unique_ptr<instruccion>> instruccionesIf;
                std::vector<std::unique_ptr<instruccion>> instruccionesElse;
                i = analyzeToBracket(tokens, ids, instruccionesIf, i+1);
                if(ids[i][0] == ELSE && ids[i][1] == '{')
                {
                    i = analyzeToBracket(tokens, ids, instruccionesElse, i+1);
                    i--;
                }
                arbolParcial.emplace_back(std::unique_ptr<ifElse>(new ifElse(std::move(exp), std::move(instruccionesIf), std::move(instruccionesElse))));

            }
            else if(!ids[i].empty()){
                throw(CompilationException("Error sintactico", tokens[i].second));
            }

        }
        return i;
    }

    void sintacticAnalyzer::copia(int index, int inicio, int final, tokenMatrix& tokens, std::vector<std::string>& ans){
        for(int i = inicio;i < final;i++)
        {
            ans.emplace_back(tokens[index].first[i]);
        }
    }

    void sintacticAnalyzer::copiaIds(int index, int inicio, int final, std::vector<std::vector<int>> &tokens,
                                     std::vector<int> &ans) {
        for(int i = inicio;i < final;i++)
        {
            ans.emplace_back(tokens[index][i]);
        }

    }
}
