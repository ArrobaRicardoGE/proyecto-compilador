#pragma once

#include "expresion.h"

namespace gm {
    class read : public expresion {
    public:
        explicit read(std::vector<std::string> tokens_);

        void evaluar(int& a) override;
        void evaluar(double& a) override;
        void evaluar(std::string& a) override;
    };
}

