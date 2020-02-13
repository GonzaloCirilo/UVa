#include <stdio.h>

void triangle(int a){
    for(int i = 0; i < a - 1; i++){
        for(int j = 0; j <= i; j++){
            putchar('0' + i + 1);
        }
        putchar('\n');
    }

    for(int j = 0; j < a; j++){
            putchar(a + '0');
    }
    putchar('\n');
    for(int i = a - 1; i > 0; i--){
        for(int j = 0; j < i; j++){
            putchar(i + '0');
        }
        putchar('\n');
    }

}

int main(){
    int t, a, f;
    scanf("%d", &t);
    while(t--){
        scanf("%d\n%d", &a, &f);
        for(int i = 0; i < f; i++){
            if(i != 0)
                printf("\n");
            triangle(a);
        }
        if(t != 0)
            printf("\n");
    }
    return 0;
}