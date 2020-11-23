#pragma once
#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_map>
#include "util.h"

namespace gm{
    const std::unordered_map<int,int> ORDER_OPERATIONS(
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
                {NOT,3},         //!=
                {OR,2},          //||
                {AND,1}          //&&
            });
    class expressionEvaluator{
    public:
        expressionEvaluator();
        int evaluate(std::vector<int> &tokens, std::vector<std::string> &values);
    private:
        std::stack<int> st;
        std::queue<int> qu;
        static bool isoperator(int c);
        static bool isgreater(int c1, int c2);
        static int operation(int a, int b, int c);
    };
}