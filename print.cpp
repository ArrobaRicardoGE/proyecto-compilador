#include "print.h"
#include <iostream>

namespace gm{
    print::print(std::unique_ptr<expresion> evaluable_) : evaluable(std::move(evaluable_)) {}

    void print::ejecutar() {
        double a;
        std::string b;
        evaluable->evaluar(a);
        evaluable->evaluar(b);
        if(b == evaluable->dummystring){
            std::cout<<a<<std::endl;
        }
        else{
            std::cout<<b<<std::endl;
        }
    }
}
