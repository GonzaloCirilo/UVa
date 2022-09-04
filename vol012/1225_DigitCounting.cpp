#include <stdio.h>

int main(){
    int n, t;
    int table [10][10002] = {};
    for (int i = 1; i < 10000; i++) {
        for(int j = 0; j < 10; j++) {
            table[j][i] = table[j][i - 1];
        }
        int aux = i;
        while(aux){
            int digit = aux % 10;
            table[digit][i]++;
            aux /= 10;
        }
    }
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i = 0; i < 10; i++){
            if(i != 0) printf(" ");
            printf("%d", table[i][n]);
        }
        printf("\n");
    }
    return 0;
}