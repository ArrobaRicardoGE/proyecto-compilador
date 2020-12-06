#pragma once
#include <utility>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>

namespace gm {
    using tokenMatrix = std::vector<std::pair<std::vector<std::string>,int>>;
    const char DELIMITER = ' ';
    const int BOOL = 200;
    const int INT = 201;
    const int FLOAT = 203;
    const int STRING = 204;
    const int TRUE = 300;
    const int FALSE = 301;
    const int ASIGNAR = 400;
    const int MENOR_IGUAL = 500;
    const int MAYOR_IGUAL = 501;
    const int IGUAL = 502;
    const int DIFERENTE = 503;
    const int AND = 600;
    const int OR = 601;
    const int NOT = 602;
    const int BREAK = 700;
    const int WHILE = 701;
    const int IF = 702;
    const int ELSE = 703;
    const int FOR = 704;
    const int TO = 705;
    const int READ = 800;
    const int PRINT = 801;
    const int INTEGER_VALUE = 900;
    const int FLOAT_VALUE = 901;
    const int STRING_VALUE = 902;
    const int VARIABLE = 1000;

    const std::unordered_map<std::string, int> WORD_MAP(
            {
                {"int", INT},
                {"float", FLOAT},
                {"string", STRING},
                {"bool", BOOL},
                {"True", TRUE},
                {"False", FALSE},
                {"#", '#'},
                {"\"", '\"'},
                {":=", ASIGNAR},
                {"*", '*'},
                {"/", '/'},
                {"+", '+'},
                {"-", '-'},
                {"<", '<'},
                {">", '>'},
                {"<=", MENOR_IGUAL},
                {">=", MAYOR_IGUAL},
                {"==", IGUAL},
                {"!=", DIFERENTE},
                {"&&", AND},
                {"||", OR},
                {"!!", NOT},
                {"(", '('},
                {")", ')'},
                {"break", BREAK},
                {"while", WHILE},
                {"if", IF},
                {"else",ELSE},
                {"for",FOR},
                {"to",TO},
                {"{", '{'},
                {"}", '}'},
                {"Read", READ},
                {"Print", PRINT},

            });

    void split(const std::string& s, std::vector<std::string>& answer, char delimiter = DELIMITER);
    bool issymbol(char c);

    class CompilationException:virtual public std::exception{
    private:
        int lineNum;
        std::string additionalInfo;
    public:
        CompilationException(std::string additionalInfo, int lineNum):additionalInfo(std::move(additionalInfo)),lineNum(lineNum){};
        virtual const char* what() const noexcept;
        virtual int line() const noexcept;
        virtual std::string info() noexcept;
    };
    struct Debug{
        static bool debug;
    };
} //gm

