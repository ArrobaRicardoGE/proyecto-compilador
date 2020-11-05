#include "util.h"

namespace gm{

    std::vector<std::string> split(const std::string& s, char delimiter){
        std::string partialAns;
        std::vector<std::string> answer;
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
        return answer;
    }

} // gm