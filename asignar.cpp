#include <iostream>
#include <utility>
#include "asignar.h"

namespace gm{
    asignar::asignar(std::string variable_, std::unique_ptr<expresion> expresion_) : variable(std::move(variable_)), expr(std::move(expresion_)) {}
    void asignar::ejecutar(){
        int tipo;
        double dummy;
        std::string dummyS;
        table->getValue(variable, tipo, dummy, dummyS);
        if(tipo == STRING)
        {
            std::string value;
            expr->evaluar(value);
            if(value == expr->dummystring){
                throw(CompilationException("Asignacion entre tipos no compatibles, con variable " + variable, 0));
            }

            double dummyDouble = 0;
            table->changeValue(variable, tipo, dummyDouble, value);
        }
        else if(tipo == FLOAT)
        {
            double value;
            expr->evaluar(value);
            if(value == expr->dummydouble){
                throw(CompilationException("Asignacion entre tipos no compatibles, con variable " + variable, 0));
            }
            std::string dummyString;
            table->changeValue(variable, tipo, value, dummyString);
        }
        else if(tipo == INT){
            int value;

            expr->evaluar(value);
            if(value == expr->dummyint){
                throw(CompilationException("Asignacion entre tipos no compatibles, con variable " + variable, 0));
            }
            std::string dummyString;
            table->changeValue(variable, tipo, value, dummyString);

        }
        else if(tipo == BOOL)
        {
            int value;
            expr->evaluar(value);
            if(value == expr->dummyint){
                throw(CompilationException("Asignacion entre tipos no compatibles, con variable " + variable, 0));
            }
            if(value != 0) value = 1;

            std::string dummyString;
            table->changeValue(variable, tipo, value, dummyString);

        }
        else{
            throw(CompilationException("Tipo de variable "+ variable + " no encontrado", 0));
        }

    }


}