#include "lexicalAnalyzer.h"

#include <utility>

namespace gm{

    lexicalAnalyzer::lexicalAnalyzer() = default;

    void lexicalAnalyzer::analyze(const std::string& filename, tokenMatrix& tokensByLine, std::vector<std::vector<int>>& ids)
    {
        analyzeSyntax(filename, tokensByLine);
    }

    void lexicalAnalyzer::wordToken(const std::string &inputLine, int &it, std::string &token){
        while(it < inputLine.size() && isalnum(inputLine[it]))
            token += inputLine[it++];
    }
    void lexicalAnalyzer::numericToken(const std::string &inputLine, int &it, std::string &token){
        while(it < inputLine.size() && (isdigit(inputLine[it]) || inputLine[it] == '.'))
            token += inputLine[it++];
    }
    void lexicalAnalyzer::symbolToken(const std::string &inputLine, int &it, std::string &token){
        //Check for symbols that could be together but can't be mixed with other symbols
        if(inputLine[it] == '(' || inputLine[it] == ')' || inputLine[it] == '{' || inputLine[it] == '}'){
            token += inputLine[it++];
            return;
        }
        while(it < inputLine.size() && issymbol(inputLine[it]))
            token += inputLine[it++];
    }
    void lexicalAnalyzer::stringToken(const std::string &inputLine, int &it, std::string &token){
        //opening quote
        token += inputLine[it++];
        while(it < inputLine.size() && inputLine[it] != '\"'){
            if(inputLine[it] == '\\'){
                token += '\\';
                it++;
            }
            token += inputLine[it++];
        }
        //closing quote
        token += inputLine[it++];
    }

    void lexicalAnalyzer::getTokens(const std::string &inputLine, std::vector<std::string> &tokenList){
        int it = 0;
        while(it < inputLine.size()){
            //whitespace
            if(inputLine[it] == ' '){
                it++;
                continue;
            }
            //comment
            if(inputLine[it] == '#')
                return;
            std::string token;
            //word
            if(isalpha(inputLine[it]))
                wordToken(inputLine,it,token);
                //number
            else if(isdigit(inputLine[it]))
                numericToken(inputLine,it,token);
                //string
            else if(inputLine[it] == '\"')
                stringToken(inputLine,it,token);
                //symbol
            else if(issymbol(inputLine[it]))
                symbolToken(inputLine,it,token);
            else{
                //raise exception or whatever, since it is an invalid symbol
                it++;
                continue;
            }
            tokenList.emplace_back(token);
        }
    }
    void lexicalAnalyzer::analyzeSyntax(const std::string& filename,tokenMatrix& tokensByLine){
        std::ifstream inputFile;
        std::string inputLine;

        inputFile.open(filename,std::ios::in);
        if(inputFile.is_open()){
            while(getline(inputFile,inputLine)){
                //Break a line into tokens
                std::vector<std::string> tokenList;
                getTokens(inputLine,tokenList);

                if(!tokenList.empty())
                    tokensByLine.emplace_back(tokenList);
            }
            inputFile.close();
        }
        //else raise exception or whatever
    }
}
