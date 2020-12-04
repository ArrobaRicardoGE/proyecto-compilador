#include <iostream>
#include "expresionMatematica.h"
#include "expressionEvaluator.h"

namespace gm{
    expresionMatematica::expresionMatematica(std::vector<std::string>&& tokens_, std::vector<int>&& ids) : expresion(std::move(tokens_), std::move(ids)) {}
    void expresionMatematica::evaluar(int& a)
    {
        if(ids[0] != STRING_VALUE ) {
            a = expressionEvaluator().evaluate(ids, tokens, table);
        }
        else a = dummyint;
    }
    void expresionMatematica::evaluar(double &a) {
        if(ids[0] != STRING_VALUE){
            a = expressionEvaluator().evaluate(ids, tokens, table);
        }
        else a = dummydouble;
    }
    void expresionMatematica::evaluar(std::string& a)
    {
        if(ids[0] == STRING_VALUE)
        {
            a = tokens[0].substr(1,tokens[0].size()-2);
        }
        else if(ids[0] == VARIABLE && ids.size() == 1)
        {
            double dummyDouble = 0;
            int type;
            table->getValue(tokens[0], type, dummyDouble, a);
        }
        else {
            a = dummystring;
        }
    }
}