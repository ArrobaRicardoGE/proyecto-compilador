#include "ciclo.h"
#include <iostream>

namespace gm{
    ciclo::ciclo(std::unique_ptr<expresion> condicion_, std::vector<std::unique_ptr<instruccion>> &&instrucciones_) : condicion(std::move(condicion_)), instrucciones(std::move(instrucciones_)) {}
    void ciclo::ejecutar() {
        int a = 0;
        condicion->evaluar(a);
        while(a != condicion->dummyint && a) {
            for (const auto &x : instrucciones) {
                x->ejecutar();
            }
            condicion->evaluar(a);
        }

    }
}
