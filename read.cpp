#include "read.h"
#include <iostream>
#include <utility>

namespace gm{
    read::read(std::vector<std::string> tokens_) : expresion(std::move(tokens_)) {}
    void read::evaluar(int &a) {
        std::cout<<"Leyendo entero"<<std::endl;
    }
    void read::evaluar(double &a) {
        std::cout<<"Leyendo double"<<std::endl;
    }
    void read::evaluar(std::string &a) {
        std::cout<<"Leyendo string"<<std::endl;
    }
}
