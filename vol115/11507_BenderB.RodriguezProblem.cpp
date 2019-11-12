#include <stdio.h>

int main(){
    int l;

    while(scanf("%d\n", &l) && l){
        char s, v, ansS = '+', ansV = 'x';
        for(int i = 0; i < l - 1; i++){
            s = getchar();
            v = getchar();
            getchar();
            if(s == 'N')
                continue;
            if(s == '-' && v == 'y'){
                if(ansS == '+' && ansV == 'x') ansS = '-', ansV = 'y';
                else if(ansS == '-' && ansV == 'x') ansS = '+', ansV = 'y';
                else if(ansS == '+' && ansV == 'y') ansS = '+', ansV = 'x';
                else if(ansS == '-' && ansV == 'y') ansS = '-', ansV = 'x';
            }
            if(s == '+' && v == 'y'){
                if(ansS == '+' && ansV == 'x') ansS = '+', ansV = 'y';
                else if(ansS == '-' && ansV == 'x') ansS = '-', ansV = 'y';
                else if(ansS == '+' && ansV == 'y') ansS = '-', ansV = 'x';
                else if(ansS == '-' && ansV == 'y') ansS = '+', ansV = 'x';
            }
            if(s == '-' && v == 'z'){
                if(ansS == '+' && ansV == 'x') ansS = '-', ansV = 'z';
                else if(ansS == '-' && ansV == 'x') ansS = '+', ansV = 'z';
                else if(ansS == '+' && ansV == 'z') ansS = '+', ansV = 'x';
                else if(ansS == '-' && ansV == 'z') ansS = '-', ansV = 'x';
            }
            if(s == '+' && v == 'z'){
                if(ansS == '+' && ansV == 'x') ansS = '+', ansV = 'z';
                else if(ansS == '-' && ansV == 'x') ansS = '-', ansV = 'z';
                else if(ansS == '+' && ansV == 'z') ansS = '-', ansV = 'x';
                else if(ansS == '-' && ansV == 'z') ansS = '+', ansV = 'x';
            }
            
        }
        printf("%c%c\n", ansS, ansV);
    }
    return 0;
}