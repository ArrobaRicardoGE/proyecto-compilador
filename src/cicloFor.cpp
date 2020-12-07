#include "cicloFor.h"
#include <iostream>

namespace gm{


    cicloFor::cicloFor(std::unique_ptr<asignar> iterador_, std::unique_ptr<expresion> valor1_,
                       std::vector<std::unique_ptr<instruccion>>&& instrucciones_, std::string variable_) : iterador(std::move(iterador_)), valor1(std::move(valor1_)), instrucciones(std::move(instrucciones_)), variable(std::move(variable_)) {}

    void cicloFor::ejecutar() {
        int valorInicio = 0;
        iterador->expr->evaluar(valorInicio);
        int valorFinal = 0;
        valor1->evaluar(valorFinal);
        int change = 1;
        iterador->ejecutar();

        if(valorInicio == valor1->dummyint || valorFinal == valor1->dummyint){
            throw(CompilationException("Error de ejecucion en For", 0));
        }
        else if(valorInicio < valorFinal){
            change = 1;
            while(valorFinal > valorInicio)
            {
                for(const auto& x : instrucciones){
                    x->ejecutar();
                }
                int tipo = 0;
                std::string dummy;
                double getval = 0;
                table->getValue(variable, tipo, getval, dummy);
                valorInicio = (int)getval + change;
                table->changeValue(variable, tipo, valorInicio, dummy);
            }
        }
        else{
            change = -1;
            while(valorFinal < valorInicio)
            {
                for(const auto& x : instrucciones){
                    x->ejecutar();
                }
                int tipo = 0;
                std::string dummy;
                double getval = 0;
                table->getValue(variable, tipo, getval, dummy);
                valorInicio = (int)getval + change;
                table->changeValue(variable, tipo, valorInicio, dummy);
            }
        }
    }

}
