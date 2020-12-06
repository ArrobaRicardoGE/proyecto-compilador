#include "util.h"

#include <utility>

namespace gm{

    void split(const std::string& s, std::vector<std::string>& answer, char delimiter){
        std::string partialAns;
        for( const auto x: s)
        {
            if(x == delimiter)
            {
                if(!partialAns.empty())
                {
                    answer.emplace_back(std::move(partialAns));
                    partialAns.clear();
                }
            }
            else{
                partialAns.push_back(x);
            }
        }
        if(!partialAns.empty())
        {
            answer.emplace_back(std::move(partialAns));
            partialAns.clear();
        }
    }
    bool issymbol(char c) {
        return c == ':' || c == '=' || c == '*' || c == '/' || c == '+' || c == '-'
               || c == '<' || c == '>' || c == '&' || c == '|' || c == '!'
               || c == '(' || c == ')' || c == '{' || c == '}';
    }
    const char* CompilationException:: what() const noexcept{
        return "Compilation error";
    }

    int CompilationException::line() const noexcept{
        return lineNum;
    }

    std::string CompilationException::info() noexcept{
        return additionalInfo;
    }

} // gm
