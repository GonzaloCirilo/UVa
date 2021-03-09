#include <stdio.h>

int main(){
    int t;
    scanf("%d\n", &t);

    for(int i = 0; i < t; i++){
        printf("Case %d: ", i + 1);
        char c = ' ', cprint; int times = 0;
        while(c != '\n'){
            c = getchar();
            if(c >= 'A' && c <= 'Z'){
                if(times != 0){
                    for(int j = 0; j < times; j++){
                        putchar(cprint);
                    }
                    times = 0;
                }
                cprint = c;
                continue;
            }
            if(c >= '0' && c <= '9'){
                times *= 10;
                times += c - '0';
            }
        }
        for(int j = 0; j < times; j++){
            putchar(cprint);
        }
        putchar('\n');
    }

    return 0;
}