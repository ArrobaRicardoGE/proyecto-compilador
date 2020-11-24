#include <iostream>
#include <utility>
#include "asignar.h"

namespace gm{
    asignar::asignar(std::string variable_, std::unique_ptr<expresion> expresion_) : variable(std::move(variable_)), expr(std::move(expresion_)) {}
    void asignar::ejecutar(){
        std::cout<<"Asignando variable "<<variable<<std::endl;
    }


}