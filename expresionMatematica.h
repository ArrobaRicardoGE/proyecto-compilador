#pragma once
#include "expresion.h"
#include <iostream>
namespace gm {
    class expresionMatematica : public expresion {
    public:
        explicit expresionMatematica(std::vector<std::string> tokens_);
        ~expresionMatematica() = default;

        void evaluar(int& a) override;
        void evaluar(double& a) override;
        void evaluar(std::string& a) override;
    };
}

