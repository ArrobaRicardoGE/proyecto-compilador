#pragma once

#include "instruccion.h"
#include "expresion.h"
#include "asignar.h"
#include <memory>

namespace gm {
    class cicloFor : public instruccion {
    public:
    cicloFor(std::unique_ptr<asignar> iterador_, std::unique_ptr<expresion> valor1_, std::vector<std::unique_ptr<instruccion>>&& instrucciones_, std::string variable_);
    void ejecutar() override;

    std::vector<std::unique_ptr<instruccion>> instrucciones;
    std::unique_ptr<asignar> iterador;
    std::unique_ptr<expresion> valor1;
    std::string variable;
    };
}
