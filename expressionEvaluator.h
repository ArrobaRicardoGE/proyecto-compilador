#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include <math.h>
#include <memory>
#include "util.h"
#include "tablaDeValores.h"

namespace gm{
    const std::unordered_map<int,int> OPERATIONS_ORDER(
            {
                {'(',7},
                {')',7},
                {'*',6},
                {'/',6},
                {'+',5},
                {'-',5},
                {MAYOR_IGUAL,4}, //>=
                {MENOR_IGUAL,4}, //<=
                {'>',4},
                {'<',4},
                {IGUAL,4},       //==
                {DIFERENTE,4},   //!=
                {NOT,3},         //!!
                {OR,2},          //||
                {AND,1}          //&&
            });
    class expressionEvaluator{
    public:
        expressionEvaluator();
        double evaluate(std::vector<int> &tokens, std::vector<std::string> &values, std::shared_ptr<tablaDeValores> tablaValores);
    private:
        struct Token{
            int id;
            double value;
            Token(int id,double value):id(id),value(value){};
        };
        std::stack<Token> st;
        std::queue<Token> qu;
        void pushToken(Token token);
        static void convertTokens(std::vector<int> &ids, std::vector<std::string> &values, std::vector<Token> &tokens);
        static bool isoperator(int c);
        static bool isgreater(int c1, int c2);
        static double operation(double a, double b, int c);
        static void print(std::vector<Token> &tokens);
    };
}