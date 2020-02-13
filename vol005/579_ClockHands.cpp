#include <stdio.h>
#include <math.h>

int main(){
    int h, m;
    while(scanf("%d:%d", &h, &m) != EOF && (h || m)){
        double hang = 30.0 * h + m*  30.0 / 60, mang = 6.0 * m, ans = abs(hang - mang);
        if(ans > 180.0)
            ans = 360.000 - ans;
        printf("%.3lf\n", ans);
    }
    return 0;
}