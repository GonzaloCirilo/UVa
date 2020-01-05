#include <stdio.h>
#include <map>
#include <string>
using namespace std;

int main(){
    int t;
    map<string, int> conquests;
    scanf("%d\n", &t);
    
    while(t--){
        char country[76];
        scanf("%s", &country);
        if(!conquests.insert({string(country), 1}).second){
            conquests[string(country)]++;
        }
        while(true){
            char c = getchar();
            if(c == EOF || c == '\n') break;
        }
    }
    int ans = 0;
    for(auto it = conquests.begin(); it != conquests.end(); it++){
        printf("%s %d\n", (*it).first.c_str(), (*it).second);
    }   

    return 0;
}