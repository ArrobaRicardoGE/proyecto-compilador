#include "util.h"

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

    std::vector<std::vector<std::string>> analizeSyntax(const std::string& filename){
        std::ifstream inputFile;
        std::string inputLine;
        std::vector<std::vector<std::string>>tokensByLine;

        inputFile.open(filename,std::ios::in);
        if(inputFile.is_open()){
            while(getline(inputFile,inputLine)){
                std::vector<std::string> newLine;
                newLine.emplace_back(inputLine);
                tokensByLine.emplace_back(newLine);
            }
            inputFile.close();
        }
        //else raise exception or whatever
        return tokensByLine;
    }

} // gm
