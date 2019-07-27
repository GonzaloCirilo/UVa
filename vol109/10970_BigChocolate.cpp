#include <stdio.h>
int main(){
    int m, n;
    while(scanf("%d %d", &m, &n) != EOF){
        printf("%d\n", (n * m) - 1);
    }
    return 0;
}