#include <stdio.h>
#include <math.h>

int main(){
    int t, h, m;
    scanf("%d", &t);
    while(t--){
        scanf("%d:%d", &h, &m);
        double minAng = m * 6.0, hourAng = (30 * h) % 360 + m *  30.0 / 60;
        minAng = 360 - minAng; 
        hourAng = 360 - (hourAng);
        //printf("hourAng = %llf\n", hourAng);
        m = minAng / 6;
        m = m == 60? 0 : m;
        h = floor(hourAng / 30);
        h = h == 0? 12 : h;
        printf("%02d:%02d\n", h, m);
    }
    return 0;
}