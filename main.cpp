#include "util.h"

using namespace std;

//Path for testing
const string path = "C:/users/ricar/documents/up/3/dsaii/3/proyecto-compilador/";

int main(){
    //Driver program to test the syntax analyzer
    auto output = gm::analyzeSyntax(path+"testFile.txt");
    for(auto &line:output){
        for(auto &word:line){
            cout<<'['<<word<<"] ";
        }
        cout<<endl;
    }
}
