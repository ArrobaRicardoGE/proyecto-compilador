#pragma once
#include "util.h"
#include <map>

namespace gm {
    class tablaDeValores {
    public:
        tablaDeValores() = default;
        ~tablaDeValores() = default;
        void getValue(const std::string& variable, int& getType, double& numericValue, std::string& stringValue);

        void addValue(const std::string& variable, int type);

        void changeValue(const std::string& variable, int& getType, double numericValue, std::string& stringValue);

        std::map<std::string, int> variableType;
        std::map<std::string, double> numericVariables;
        std::map<std::string, std::string> stringVariables;
        const std::string dummyString = "dummyString123456790";
        const double dummyDouble = 102938475.1029348457;
    };
}

