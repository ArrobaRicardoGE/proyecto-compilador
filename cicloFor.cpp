#include "cicloFor.h"
#include <iostream>

namespace gm{


    cicloFor::cicloFor(std::unique_ptr<asignar> iterador_, std::unique_ptr<expresion> valor1_,
                       std::vector<std::unique_ptr<instruccion>>&& instrucciones_, std::string variable_) : iterador(std::move(iterador_)), valor1(std::move(valor1_)), instrucciones(std::move(instrucciones_)), variable(std::move(variable_)) {}

    void cicloFor::ejecutar() {
        std::cout<<"Dentro de ciclo for, ";
        iterador->ejecutar();
        std::cout<<"{"<<std::endl;
        for(const auto& x : instrucciones)
        {
            std::cout<<"\t";
            x->ejecutar();
        }
        std::cout<<"} Afuera de ciclo for"<<std::endl;
    }

}
