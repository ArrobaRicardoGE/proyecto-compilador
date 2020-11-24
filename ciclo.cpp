#include "ciclo.h"
#include <iostream>

namespace gm{
    ciclo::ciclo(std::unique_ptr<expresion> condicion_, std::vector<std::unique_ptr<instruccion>> &&instrucciones_) : condicion(std::move(condicion_)), instrucciones(std::move(instrucciones_)) {}
    void ciclo::ejecutar() {
        int a;
        std::cout<<"Dentro de ciclo while {"<<std::endl;
        std::cout<<"Evaluando condicion del while"<<std::endl;
        condicion->evaluar(a);
        for(const auto& x : instrucciones)
        {
            std::cout<<"\t";
            x->ejecutar();
        }
        std::cout<<"} Afuera de ciclo while"<<std::endl;
    }
}