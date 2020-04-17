#include <stdio.h>
#include <math.h>

int main(){
    int a;
    bool exists[181] = {};

    int h = 0, min = 0;
    for(int h = 0; h < 12; h++){
        for(int m = 0; m < 60; m++){
            int dh = h * 30 + (m / 12 * 6), dm = m * 6, ans = abs(dh - dm);
            if(ans > 180){
                ans = 360 - ans;
            }
            exists[ans] = true;
        }
    }
    while(scanf("%d", &a) != EOF){
        if(exists[a])
            printf("Y\n");
        else
            printf("N\n");
    }
    return 0;
}