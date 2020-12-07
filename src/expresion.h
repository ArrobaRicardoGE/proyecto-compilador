#pragma once
#include <string>
#include <memory>
#include <vector>
#include "tablaDeValores.h"

namespace gm {
    class expresion{
    public:
        expresion(std::vector<std::string>&& tokens_, std::vector<int>&& ids_);
        ~expresion() = default;
        virtual void evaluar(int& a) = 0;
        virtual void evaluar(double& a)= 0;
        virtual void evaluar(std::string& a) = 0;

        const int dummyint = -310293485;
        const double dummydouble  = 3.98766543;
        const std::string dummystring = "hey, i am a dummy string 1234567";

        std::vector<std::string>  tokens;
        std::vector<int> ids;
        static std::shared_ptr<tablaDeValores> table;
    };
}

