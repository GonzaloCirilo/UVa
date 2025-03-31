#include <stdio.h>

int main() {
    int t;
    long long a, b, c;
    scanf("%d", &t);
    for (int ti = 0; ti < t; ti++) {
        scanf("%lld %lld %lld", &a, &b, &c);
        printf("Case %d: ", ti + 1);
        if (a + b <= c || b + c <= a || c + a <= b || a == 0 || b == 0 || c == 0) {
            printf("Invalid\n");
        } else if (a == b && b == c) {
            printf("Equilateral\n");
        } else if (a == b || b == c || a == c) {
            printf("Isosceles\n");
        } else {
            printf("Scalene\n");
        }
    }
    return 0;
}