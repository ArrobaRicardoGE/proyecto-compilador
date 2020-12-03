#pragma once
#include "expresion.h"
#include <iostream>
namespace gm {
    class expresionMatematica : public expresion {
    public:
        expresionMatematica(std::vector<std::string>&& tokens_, std::vector<int>&& ids_);
        ~expresionMatematica() = default;

        void evaluar(int& a) override;
        void evaluar(double& a) override;
        void evaluar(std::string& a) override;
    };
}

