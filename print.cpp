#include "print.h"
#include <iostream>

namespace gm{
    print::print(std::unique_ptr<expresion> evaluable_) : evaluable(std::move(evaluable_)) {}

    void print::ejecutar() {
        double a = 0;
        std::string b;
        evaluable->evaluar(b);
        if(b == evaluable->dummystring){
            evaluable ->evaluar(a);
            std::cout<<a<<std::endl;
        }
        else{
            std::cout<<b<<std::endl;
        }
    }
}
