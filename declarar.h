#pragma once

#include <memory>
#include "instruccion.h"
#include "asignar.h"

namespace gm {
    class declarar : instruccion {
    public:
        declarar(int tipo_, std::unique_ptr<asignar> asignacion_);

        void ejecutar() override;

        int tipo;
        std::unique_ptr<asignar> asignacion;
    };
}


