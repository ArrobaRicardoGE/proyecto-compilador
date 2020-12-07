#pragma once
#include <string>
#include <memory>
#include "expresion.h"
#include "instruccion.h"

namespace gm {
    class asignar : public instruccion {
    public:
        asignar(std::string variable_, std::unique_ptr<expresion> expresion_);
        void ejecutar() override;

        std::string variable;
        std::unique_ptr<expresion> expr;
    };
}
