#pragma once

#include <memory>
#include "instruccion.h"
#include "expresion.h"

namespace gm {
    class ciclo : public instruccion{
    public:
        ciclo(std::unique_ptr<expresion> condicion_, std::vector<std::unique_ptr<instruccion>>&& instrucciones_);
        void ejecutar() override;

        std::unique_ptr<expresion> condicion;
        std::vector<std::unique_ptr<instruccion>> instrucciones;
    };
}
