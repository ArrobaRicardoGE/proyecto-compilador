#include "expresion.h"
#include<iostream>
namespace gm{

    expresion::expresion(std::vector<std::string>&& tokens_, std::vector<int>&& ids_) : ids(std::move(ids_)), tokens(std::move(tokens_)){}
    

}