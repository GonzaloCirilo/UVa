#include <stdio.h>
#include <stack>

using namespace std;

void emptyStack(stack<char> &s){
    while(!s.empty()){
        putchar(s.top());
        s.pop();
    }
}

int main(){
    char c;
    stack<char> s;
    do{
        c = getchar();
        if(c == ' '){
            emptyStack(s);
            putchar(' ');
        }else if(c == '\n'){
            emptyStack(s);
            putchar('\n');
        }else{
            if(c != EOF)
                s.push(c);
        }
    } while(c != EOF);
    emptyStack(s);
    return 0;
}