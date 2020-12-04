#include "tablaDeValores.h"

namespace gm{

    void tablaDeValores::getValue(const std::string &variable, int& getType, double &numericValue, std::string &stringValue) {
        auto it = variableType.find(variable);
        if(it  == variableType.end()) {
            throw CompilationException("Variable " + variable + " no encontrada en tabla de valores", 0);
        }
        getType = it->second;
        if(getType == STRING)
        {
            numericValue = dummyDouble;
            stringValue = stringVariables[variable];
        }
        else
        {
         numericValue = numericVariables[variable];
         stringValue = dummyString;
        }
    }

    void tablaDeValores::addValue(const std::string &variable, int type) {
       auto it = variableType.find(variable);
       if(it != variableType.end())
       {
          throw CompilationException("Doble declaracion de variable " + variable, 0);
       }


       variableType[variable] = type;
    }

    void tablaDeValores::changeValue(const std::string &variable, int &getType, double numericValue,
                                     std::string &stringValue) {
        auto it = variableType.find(variable);
        if(it == variableType.end())
        {
            throw CompilationException("Variable " + variable + "no encontrada", 0);
        }
        getType = it->second;
        if(getType == STRING)
        {
            stringVariables[variable] = stringValue;
        }
        else{
            numericVariables[variable] = numericValue;
        }
    }


}