#pragma once
#include <string>
#include <vector>

namespace gm {
    class expresion{
    public:
        explicit expresion(std::vector<std::string> tokens_);
        ~expresion() = default;
        virtual void evaluar(int& a) = 0;
        virtual void evaluar(double& a)= 0;
        virtual void evaluar(std::string& a) = 0;

        std::vector<std::string>  tokens;
    };
}

