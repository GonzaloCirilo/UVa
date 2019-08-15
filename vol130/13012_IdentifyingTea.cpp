#include <stdio.h>
int main(){
    int t, aux;
    while(scanf("%d", &t) != EOF){
        int p = 5, ans = 0;
        while(p--){
            scanf("%d", &aux);
            ans += (aux == t);
        }
        printf("%d\n", ans);
    }
    return 0;
}