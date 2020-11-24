#include <iostream>
#include "expresionMatematica.h"

namespace gm{
    expresionMatematica::expresionMatematica(std::vector<std::string> tokens_) : expresion(std::move(tokens_)) {}
    void expresionMatematica::evaluar(int& a)
    {
        std::cout<<"evaluando entero"<<std::endl;
    }
    void expresionMatematica::evaluar(double &a) {
        std::cout<<"evaluando doble"<<std::endl;
    }
    void expresionMatematica::evaluar(std::string& a)
    {
        std::cout<<"evaluando cadena"<<std::endl;
    }
}