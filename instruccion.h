#pragma once
#include "tablaDeValores.h"
#include <memory>

namespace gm{
    class instruccion{
    public:
        virtual void ejecutar() = 0;
        ~instruccion() = default;
        static std::shared_ptr<tablaDeValores> table;
    };


}