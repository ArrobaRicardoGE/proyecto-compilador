#include "expressionEvaluator.h"

namespace gm{
    expressionEvaluator::expressionEvaluator() = default;
    expressionEvaluator::~expressionEvaluator() = default;
    double expressionEvaluator::evaluate(std::vector<int> &ids, std::vector<std::string> &values, std::shared_ptr<tablaDeValores> tablaValores) {
        std::vector<Token> tokens;
        convertTokens(ids,values,tablaValores,tokens);
       // print(tokens);
        Token lastToken(WORD_MAP.at("("),WORD_MAP.at("("));
        for(Token token:tokens){
            if(isoperator(token.id)){
                if(token.id == WORD_MAP.at("(")) st.push(token);
                else if(token.id == WORD_MAP.at(")")){
                    while(!st.empty() && st.top().id != WORD_MAP.at("(")){
                        qu.push(st.top());
                        st.pop();
                    }
                    //Parentesis que no abre
                    if(st.empty())throw CompilationException("El parentesis ')' no coincide",0);
                    st.pop();
                }
                else
                    pushToken(token);
            }
            else qu.push(token);
            lastToken = token;
        }
        while(!st.empty()){
            //Parentesis que no cierra
            if(st.top().id == WORD_MAP.at("(")) throw CompilationException("El parentesis '(' no coincide",0);
            qu.push(st.top());
            st.pop();
        }
        while(!qu.empty()){
            Token current = qu.front();
            qu.pop();
            if(isoperator(current.id)){
                try{
                    if(st.empty())
                        throw std::exception();
                    double der = st.top().value;
                    st.pop();
                    double izq = 0.0;
                    if(current.id != WORD_MAP.at("!!")){
                        if(st.empty())
                            throw std::exception();
                        izq = st.top().value;
                        st.pop();
                    }
                    st.push(Token(FLOAT_VALUE,operation(izq,der,current.id)));
                }
                catch (std::exception &e) {
                    throw CompilationException("Expresion invalida",0);
                }
            }
            else st.push(current);
        }
        if(st.size() != 1)throw CompilationException("Expresion invalida",0);
        return st.top().value;
    }

    void expressionEvaluator::pushToken(Token token) {
        while(!st.empty()){
            if(isgreater(st.top().id,token.id)){
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

    double expressionEvaluator::operation(double a, double b, int c) {
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
                return (int)(a == b);
            case DIFERENTE:
                return (int)(a != b);
            case NOT:
                return (int)(!(bool)b);
            case OR:
                return (int)((bool)a || (bool)b);
            case AND:
                return (int)((bool)a && (bool)b);
            default:
                return 0;
        }
    }

    void expressionEvaluator::convertTokens(std::vector<int> &ids, std::vector<std::string> &values,
                                            std::shared_ptr<tablaDeValores> table, std::vector<Token> &tokens) {
        //Validar parentesis
        std::stack<int>pBalance;
        std::unordered_map<int,int>pClosing;
        for(int i = 0;i<ids.size();i++){
            if(ids[i] == WORD_MAP.at(")")){
                if(pBalance.empty())
                    throw CompilationException("El parentesis ')' no coincide",0);
                pClosing[pBalance.top()] = i;
                pBalance.pop();
            }
            if(ids[i] == WORD_MAP.at("("))
                pBalance.push(i);
        }
        if(!pBalance.empty())throw CompilationException("El parentesis '(' no coincide",0);

        //Crear lista de tokens, sustituir [-] por [-1,*] y los [+] por [1,+]
        int i = 0;
        int previous = WORD_MAP.at("(");
        std::priority_queue<int,std::vector<int>,std::greater<int>>pending;
        while(i<ids.size()){
            //Variable
            if(ids[i] == VARIABLE){
                //Sacar de la tabla de variables
                int varType;
                double valueN;
                std::string valueS;
                table->getValue(values[i],varType,valueN,valueS);
                if(varType == STRING)throw CompilationException("No es posible hacer operaciones con strings",0);
                tokens.emplace_back(ids[i],valueN);
            }
            //Operador
            else if(isoperator(ids[i])){
                //Caso +/-
                if(ids[i] == WORD_MAP.at("+") || ids[i] == WORD_MAP.at("-")){
                    if(previous == WORD_MAP.at(")") || !isoperator(previous))
                        tokens.emplace_back(WORD_MAP.at("+"),WORD_MAP.at("+"));
                    tokens.emplace_back(WORD_MAP.at("("),WORD_MAP.at("("));
                    tokens.emplace_back(INTEGER_VALUE,(ids[i] == WORD_MAP.at("-")?-1:1));
                    tokens.emplace_back(WORD_MAP.at("*"),WORD_MAP.at("*"));
                    if(i+1<ids.size() && ids[i+1] == WORD_MAP.at("("))
                        pending.push(pClosing[i+1]);
                    else pending.push(i+1);
                }
                //Otro caso
                else tokens.emplace_back(ids[i],ids[i]);
            }
            //Bool
            else if(ids[i] == TRUE || ids[i] == FALSE)
                tokens.emplace_back(ids[i],ids[i] == TRUE?1:0);
            //String -> no permitido
            else if(ids[i] == STRING_VALUE)
                throw CompilationException("No es posible hacer operaciones con strings",0);
            //Valor
            else
                tokens.emplace_back(ids[i],std::stod(values[i]));
            if(!pending.empty() && pending.top() == i){
                tokens.emplace_back(WORD_MAP.at(")"),WORD_MAP.at(")"));
                pending.pop();
            }
            previous = ids[i];
            i++;
        }
        while(!pending.empty()){
            tokens.emplace_back(WORD_MAP.at(")"),WORD_MAP.at(")"));
            pending.pop();
        }
    }

    void expressionEvaluator::print(std::vector<Token> &tokens) {
        for(auto i:tokens){
            if(isoperator(i.id))
                std::cout<<(char)i.id<<' ';
            else std::cout<<i.value<<' ';
        }
        std::cout<<std::endl;
    }
}