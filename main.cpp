#include "util.h"

using namespace std;

const string path = "C:/users/ricar/documents/up/3/dsaii/3/proyecto-compilador/";

int main(){
    auto output = gm::analyzeSyntax(path+"testFile.txt");
    for(auto &line:output){
        for(auto &word:line){
            cout<<'['<<word<<"] ";
        }
        cout<<endl;
    }
}
