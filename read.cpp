#include "read.h"
#include <iostream>
#include <utility>

namespace gm{
    read::read(std::vector<std::string>&& tokens_, std::vector<int>&& ids_) : expresion(std::move(tokens_), std::move(ids_)) {}
    void read::evaluar(int &a) {
        std::cout<<"Leyendo de consola"<<std::endl;
    }
    void read::evaluar(double &a) {
        std::cout<<"Leyendo de consola"<<std::endl;
    }
    void read::evaluar(std::string &a) {
        std::cout<<"Leyendo consola"<<std::endl;
    }
}
