#include <stdio.h>

int main(){
    int h1, m1, h2, m2, max = 24 * 60;

    while(scanf("%d %d %d %d", &h1, &m1, &h2, &m2) && (h1 || m1 || h2 || m2)){
        int s1 = m1 + h1 * 60, s2 = m2 + h2 * 60, ans;

        if(s1 > s2){
            ans = max - (s1 - s2);
        }else{
            ans = s2 - s1;
        }
        printf("%d\n", ans);
    }
    return 0;
}