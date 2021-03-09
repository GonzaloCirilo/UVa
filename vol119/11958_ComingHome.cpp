#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int t, sh, sm, k, th, tm, ans, d;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        ans = 99999;
        printf("Case %d: ", i + 1);
        scanf("%d %d:%d", &k, &sh, &sm);
        for(int j = 0; j < k; j++){
            scanf("%d:%d %d", &th, &tm, &d);
            int duration = ((th * 60 + tm) - (sh * 60 + sm) + 1440) % 1440 + d;
            ans = min(ans, duration);
        }
        printf("%d\n", ans);
    }
    return 0;
}