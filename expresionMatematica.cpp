#include <iostream>
#include "expresionMatematica.h"

namespace gm{
    expresionMatematica::expresionMatematica(std::vector<std::string>&& tokens_, std::vector<int>&& ids) : expresion(std::move(tokens_), std::move(ids)) {}
    void expresionMatematica::evaluar(int& a)
    {
        std::cout<<"Resultado de Expresion"<<std::endl;
    }
    void expresionMatematica::evaluar(double &a) {
        std::cout<<"Resultado de Expresion"<<std::endl;
    }
    void expresionMatematica::evaluar(std::string& a)
    {
        std::cout<<"Resultado de Expresion"<<std::endl;
    }
}