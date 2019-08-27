#include <stdio.h>
int main(){
    int n, l, t, mangos[10], limit[10];
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d: ", i);
        scanf("%d %d", &n, &l);
        int sum = 0;
        for(int j = 0; j < n; j++){
            scanf("%d", &mangos[j]);
            sum += mangos[j];
        }
        bool win = sum <= l;
        for(int j = 0; j < n; j++){
            scanf("%d", &limit[j]);
            win = win && (limit[j] - mangos[j] >= 0);
        }
        if(win)
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}