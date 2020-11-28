#include "expressionEvaluator.h"

namespace gm{
    expressionEvaluator::expressionEvaluator() = default;

    int expressionEvaluator::evaluate(std::vector<int> &tokens, std::vector<std::string> &values) {
        //Ajustar esto para float
        int i = 0;
        for(int token:tokens){
            if(isoperator(token)){
                if(token == '(') st.push(token);
                else if(token == ')'){
                    while(!st.empty() && st.top() != '('){
                        qu.push(st.top());
                        st.pop();
                    }
                    //Parentesis que no abre
                    if(st.empty())throw CompilationException("Invalid expression",0);
                    st.pop();
                }
                else{
                    while(!st.empty()){
                        if(isgreater(st.top(),token)){
                            qu.push(st.top());
                            st.pop();
                        }
                        else break;
                    }
                    st.push(token);
                }
            }
            else qu.push(std::stoi(values[i]));
            i++;
        }
        while(!st.empty()){
            //Parentesis que no cierra
            if(st.top() == '(') throw CompilationException("Invalid expression",0);
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
                    throw CompilationException("Invalid expression",0);
                }
            }
            else st.push(current);
        }
        if(st.size() != 1)throw CompilationException("Invalid expression",0);
        return st.top();
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
}