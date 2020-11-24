#include <iostream>
#include "ifElse.h"

namespace gm{
    ifElse::ifElse(std::unique_ptr<expresion> condicionIf_,
                   std::vector<std::unique_ptr<instruccion>>&& instruccionesIf_,
                   std::vector<std::unique_ptr<instruccion>>&& instruccionesElse_) : condicionIf(std::move(condicionIf_)),
                   instruccionesIf(std::move(instruccionesIf_)), instruccionesElse(std::move(instruccionesElse_)) {}

    void ifElse::ejecutar() {
        std::cout<<"Checando condicion del if"<<std::endl;
        int dummy;
        condicionIf->evaluar(dummy);
        std::cout<<"Ejecutando instrucciones del if"<<std::endl;
        for(const auto& x : instruccionesIf)
        {
            x->ejecutar();
        }
        std::cout<<"Ejecutando instrucciones del else"<<std::endl;
        for(const auto& x: instruccionesElse)
        {
            x->ejecutar();
        }

    }
}