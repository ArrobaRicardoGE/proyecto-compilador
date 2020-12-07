#pragma once

#include <memory>
#include "expresion.h"
#include "instruccion.h"
namespace gm {
    class print : public instruccion{
    public:
        explicit print(std::unique_ptr<expresion> evaluable_);

        void ejecutar() override;
        std::unique_ptr<expresion> evaluable;
    };
}



