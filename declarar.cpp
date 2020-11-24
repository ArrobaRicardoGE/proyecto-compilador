#include "declarar.h"

#include <utility>
#include <iostream>

namespace gm{
    declarar::declarar(int tipo_, std::unique_ptr<asignar> asignacion_) : tipo(tipo_), asignacion(std::move(asignacion_)){}

    void declarar::ejecutar()
    {
        std::cout<<"Declarando variable de tipo "<<tipo<<", ";
        asignacion->ejecutar();
    }
}
