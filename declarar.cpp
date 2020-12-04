#include "declarar.h"

#include <utility>
#include <iostream>

namespace gm{
    declarar::declarar(int tipo_, std::unique_ptr<asignar> asignacion_) : tipo(tipo_), asignacion(std::move(asignacion_)){}

    void declarar::ejecutar()
    {
      table->addValue(asignacion->variable, tipo);

        asignacion->ejecutar();
    }
}
