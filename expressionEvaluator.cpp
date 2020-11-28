#include "expressionEvaluator.h"

namespace gm{
    expressionEvaluator::expressionEvaluator() = default;

    int expressionEvaluator::evaluate(std::vector<int> &tokens, std::vector<std::string> &values) {
        //Ajustar esto para float
        int i = 0;
        int lastToken = WORD_MAP.at("(");
        for(int token:tokens){
            if(isoperator(token)){
                if(token == WORD_MAP.at("(")) st.push(token);
                else if(token == WORD_MAP.at(")")){
                    while(!st.empty() && st.top() != WORD_MAP.at("(")){
                        qu.push(st.top());
                        st.pop();
                    }
                    //Parentesis que no abre
                    if(st.empty())throw CompilationException("Invalid expression, open parenthesis",0);
                    st.pop();
                }
                else{
                    //Caso simbolo +/-
                    if(token == WORD_MAP.at("-") || token == WORD_MAP.at("+")){
                        //Si esta como simbolo de operacion
                        if(lastToken == WORD_MAP.at(")") || OPERATIONS_ORDER.find(lastToken) == OPERATIONS_ORDER.end())
                            pushToken(WORD_MAP.at("+"));
                        qu.push((token == WORD_MAP.at("-")?-1:1));
                        pushToken(WORD_MAP.at("*"));
                    }
                    else pushToken(token);
                }
            }
            else qu.push(std::stoi(values[i]));
            lastToken = token;
            i++;
        }
        while(!st.empty()){
            //Parentesis que no cierra
            if(st.top() == WORD_MAP.at("(")) throw CompilationException("Invalid expression. Closed parenthesis",0);
            qu.push(st.top());
            st.pop();
        }
        while(!qu.empty()){
            int current = qu.front();
            qu.pop();
            if(isoperator(current)){
                try{
                    if(st.empty())
                        throw std::exception();
                    int der = st.top();
                    st.pop();
                    int izq = 0;
                    if(current != WORD_MAP.at("!!")){
                        if(st.empty())
                            throw std::exception();
                        izq = st.top();
                        st.pop();
                    }
                    st.push(operation(izq,der,current));
                }
                catch (std::exception &e) {
                    throw CompilationException("Invalid expression1",0);
                }
            }
            else st.push(current);
        }
        if(st.size() != 1)throw CompilationException("Invalid expression2",0);
        return st.top();
    }

    void expressionEvaluator::pushToken(int token) {
        while(!st.empty()){
            if(isgreater(st.top(),token)){
                qu.push(st.top());
                st.pop();
            }
            else break;
        }
        st.push(token);
    }

    bool expressionEvaluator::isoperator(int c) {
        return OPERATIONS_ORDER.find(c) != OPERATIONS_ORDER.end();
    }

    bool expressionEvaluator::isgreater(int c1, int c2) {
        if(c1 == '(')return false;
        return OPERATIONS_ORDER.find(c1)->second >= OPERATIONS_ORDER.find(c2)->second;
    }

    int expressionEvaluator::operation(int a, int b, int c) {
        switch (c) {
            case '*':
                return a*b;
            case '/':
                return a/b;
            case '+':
                return a+b;
            case '-':
                return a-b;
            case MAYOR_IGUAL:
                return (int)(a >= b);
            case MENOR_IGUAL:
                return (int)(a <= b);
            case '>':
                return (int)(a > b);
            case '<':
                return (int)(a < b);
            case IGUAL:
                return int(a == b);
            case DIFERENTE:
                return int(a != b);
            case NOT:
                return int(!b);
            case OR:
                return int(a || b);
            case AND:
                return int(a && b);
            default:
                return 0;
        }
    }
    void expressionEvaluator::getVariables(std::vector<int> &tokens, std::vector<std::string> &values) {
        //Replace variables
        return;
    }
}