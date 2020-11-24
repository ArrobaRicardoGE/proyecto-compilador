#include "print.h"
#include <iostream>

namespace gm{
    print::print(std::unique_ptr<expresion> evaluable_) : evaluable(std::move(evaluable_)) {}

    void print::ejecutar() {
        std::cout<<"Imprimiendo ";
        int a = 3;
        evaluable->evaluar(a);
    }
}
