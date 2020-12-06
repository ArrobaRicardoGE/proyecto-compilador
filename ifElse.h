#pragma once
#include "instruccion.h"
#include "expresion.h"
#include <memory>

namespace gm {
    class ifElse : public instruccion {
    public:
        ifElse(std::unique_ptr<expresion> condicionIf_, std::vector<std::unique_ptr<instruccion>>&& instruccionesIf_, std::vector<std::unique_ptr<instruccion>>&& instruccionesElse_);

        void ejecutar() override;

        std::unique_ptr<expresion> condicionIf;
        std::vector<std::unique_ptr<instruccion>> instruccionesIf;
        std::vector<std::unique_ptr<instruccion>> instruccionesElse;
    };
}
