#pragma once

#include <memory>
#include "instruccion.h"
#include "util.h"

namespace gm {
    class sintacticAnalyzer {
    public:
        sintacticAnalyzer() = default;
        void analyze(tokenMatrix& tokens, std::vector<std::vector<int>>& ids, std::vector<std::unique_ptr<instruccion>>& arbolSintactico);

        int analyzeToBracket(tokenMatrix& tokes, std::vector<std::vector<int>>& ids, std::vector<std::unique_ptr<instruccion>>& arbolParcial, int index);

        void copia(int index, int inicio, int final, tokenMatrix& tokens, std::vector<std::string> ans);

    };
}
