#include <stdio.h>

int main(){
    int n;
    while (scanf("%d", &n) && n){
        int ans = 0;

        while(n >= 3){
            int q = n / 3;
            ans += q;
            n += q -  q * 3;   
        }
        if(n == 2)
            ans++;
        printf("%d\n", ans);
    }
    
    return 0;
}