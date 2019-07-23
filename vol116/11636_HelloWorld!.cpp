#include <stdio.h>
#include <math.h>
int main(){
    int n, cont = 1;
    while (scanf("%d", &n) && n > 0){
        printf("Case %d: %d\n", cont++, (int)ceil(log2(n)));
    }
    
}