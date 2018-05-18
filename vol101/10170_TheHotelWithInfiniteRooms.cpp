#include <stdio.h>
#include <math.h>
 
int main (){
    long long s, d;
 
    while ( scanf ("%lld %lld", &s, &d) != EOF ) {
        d = (d + (s * (s - 1)) / 2) * 2;
        long long n = (long long)ceil ((sqrt (4 * d + 1) - 1) / 2.0);
        printf ("%lld\n", n);
    }
 
    return 0;
}