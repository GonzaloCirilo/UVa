#include <stdio.h>
int main(){
    long long seq[55] = {};
    int n;
    seq[1] = 1;
    seq[2] = 2;
    for(int i = 3; i < 55; i++){
        seq[i] = seq[i - 1] + seq[i - 2];
    }
    while(scanf("%d", &n) && n) {
        printf("%lld\n", seq[n]);
    }
    return 0;
}