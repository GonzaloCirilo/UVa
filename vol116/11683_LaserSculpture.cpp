#include <stdio.h>

int main(){
    int a, c, x;
    while(scanf("%d", &a) && a){
        scanf("%d", &c);
        int ans = 0;
        for(int i = 0; i < c; i++){
            scanf("%d", &x);
            if(a > x){
                ans += (a - x);
            }
            a = x;
        }
        printf("%d\n", ans);
    }
    return 0;
}