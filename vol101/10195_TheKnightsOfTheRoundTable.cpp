#include <stdio.h>
#include <math.h>

int main(){
    double a, b, c;
    while(scanf("%lf %lf %lf", &a, &b, &c) != EOF){
        double s = (a + b + c) / 2;
        double r;
        if(a == 0.0 || b == 0.0 || c == 0.0)
            r = 0.0;
        else
            r = sqrt(s * (s - a) * (s - b) * (s - c)) / s;
        printf("The radius of the round table is: %.3lf\n", r);
    }
    return 0;
}   