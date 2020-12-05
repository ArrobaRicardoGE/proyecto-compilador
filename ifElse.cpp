#include <iostream>
#include "ifElse.h"

namespace gm{
    ifElse::ifElse(std::unique_ptr<expresion> condicionIf_,
                   std::vector<std::unique_ptr<instruccion>>&& instruccionesIf_,
                   std::vector<std::unique_ptr<instruccion>>&& instruccionesElse_) : condicionIf(std::move(condicionIf_)),
                   instruccionesIf(std::move(instruccionesIf_)), instruccionesElse(std::move(instruccionesElse_)) {}

    void ifElse::ejecutar() {
       int a;
       condicionIf -> evaluar(a);
       if(a!= condicionIf->dummyint && a)
       {
           for(const auto& x : instruccionesIf)
           {
               x->ejecutar();
           }
       }
       else{
           for(const auto& x: instruccionesElse)
           {
               x->ejecutar();
           }
       }

    }
}