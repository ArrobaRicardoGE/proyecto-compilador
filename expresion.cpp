#include "expresion.h"
#include<iostream>
namespace gm{

    expresion::expresion(std::vector<std::string> tokens_) : tokens(std::move(tokens_)) {}

}