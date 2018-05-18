#include <stdio.h>
#include <math.h>
int main(){
    long long s, d;
    while (scanf("%lld %lld", &s, &d) != EOF) {
        d = (d + (s * (s - 1)) / 2) * 2;
        long long n = (long long) round(sqrt(d));
        printf("%lld\n", n);
    }
    return 0;
}