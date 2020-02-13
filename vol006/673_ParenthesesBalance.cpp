#include <stdio.h>
#include <stack>
using namespace std;

int main(){
    int t; 
    scanf("%d\n", &t);
    while(t--){
        char c = ' ';
        stack <char> s;
        bool valid = true;
        while(c != '\n' && c != EOF){
            c = getchar() ;
            if(c == '(' || c == '['){
                s.push(c);
            }else{
                if((c == ']' && !s.empty() && s.top() == '[') || (c == ')' && !s.empty() && s.top() == '(')){
                    s.pop();
                }else{
                    if(c == ']' || c == ')'){
                        valid = false;
                        //printf("==%d==", cont);
                    }
                }
            }
        }
        if(valid && s.empty())
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}