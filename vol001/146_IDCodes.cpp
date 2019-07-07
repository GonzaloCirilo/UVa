#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
int main(){
    char s[100];
    fgets(s,100, stdin);
    while(s[0] != '#'){
        int len = strlen(s) - 1;
        if(next_permutation(s,s+len)){
            cout << s;
        }else{
            cout << "No Successor" << endl;
        }
        fgets(s,100, stdin);
    }
}