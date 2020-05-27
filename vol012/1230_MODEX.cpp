#include <stdio.h>

int main(){
    int t, x, y, n;

    scanf("%d", &t);
    while(t--){
        scanf("%d %d %d", &x, &y, &n);
        //printf("==%d %d %d\n", x, y, n);
        int ans = 1;
        while(y){
            if(y % 2 == 1){
                ans = ((ans % n) * (x % n)) % n;
            }
            x = ((x % n) * (x % n)) % n;
            y /= 2;
        }

        printf("%d\n", ans);
    }
    scanf("%d", &t);
    return 0;
}