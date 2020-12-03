#pragma once

#include "expresion.h"

namespace gm {
    class read : public expresion {
    public:
        read(std::vector<std::string>&& tokens_, std::vector<int>&& ids_);

        void evaluar(int& a) override;
        void evaluar(double& a) override;
        void evaluar(std::string& a) override;
    };
}

