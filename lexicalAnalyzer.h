#pragma once

#include <fstream>
#include "util.h"


namespace gm {
    using tokenMatrix = std::vector<std::vector<std::string>>;
    class lexicalAnalyzer {
    public:
        lexicalAnalyzer();
        void analyze(const std::string& filename, tokenMatrix& tokensByLine, std::vector<std::vector<int>>& ids);

    private:
        void getIds(tokenMatrix& tokensByLine, std::vector<std::vector<int>>& ids);
        int getTokenId(const std::string& token);
        bool variable(const std::string& token);
        void analyzeSyntax(const std::string& filename, tokenMatrix& tokensByLine);
        void getTokens(const std::string &inputLine, std::vector<std::string>& tokenList);
        void wordToken(const std::string &inputLine, int &it, std::string &token);
        void numericToken(const std::string &inputLine, int &it, std::string &token);
        void symbolToken(const std::string &inputLine, int &it, std::string &token);
        void stringToken(const std::string &inputLine, int &it, std::string &token);

    };
} //gm
