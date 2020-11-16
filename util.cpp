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
    bool issymbol(char c){
        return c == ':' || c == '=' || c == '*' || c == '/' || c == '+' || c == '-'
                        || c == '<' || c == '>' || c == '&' || c == '|' || c == '!'
                        || c == '(' || c == ')' || c == '{' || c == '}';
    }
    void wordToken(const std::string &inputLine, int &it, std::string &token){
        while(it < inputLine.size() && isalnum(inputLine[it]))
            token += inputLine[it++];
    }
    void numericToken(const std::string &inputLine, int &it, std::string &token){
        while(it < inputLine.size() && (isdigit(inputLine[it]) || inputLine[it] == '.'))
            token += inputLine[it++];
    }
    void symbolToken(const std::string &inputLine, int &it, std::string &token){
        //Check for symbols that could be together but can't be mixed with other symbols
        if(inputLine[it] == '(' || inputLine[it] == ')' || inputLine[it] == '{' || inputLine[it] == '}'){
            token += inputLine[it++];
            return;
        }
        while(it < inputLine.size() && issymbol(inputLine[it]))
            token += inputLine[it++];
    }
    void stringToken(const std::string &inputLine, int &it, std::string &token){
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

    void getTokens(const std::string &inputLine, std::vector<std::string> &tokenList){
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
    std::vector<std::vector<std::string>> analyzeSyntax(const std::string& filename){
        std::ifstream inputFile;
        std::string inputLine;
        std::vector<std::vector<std::string>>tokensByLine;

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
        return tokensByLine;
    }

} // gm
