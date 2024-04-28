#include <stdio.h>

int main() {
    int t, a = 0; 
    scanf("%d", &t);
    double l, wi, d, we; 
    while (t--) {
        scanf("%lf %lf %lf %lf", &l, &wi, &d, &we);
        if (we <= 7.0 && (l + wi + d <= 125 || (l <= 56 && wi <= 45 && d <= 25))) {
            printf("1\n");
            a++;
        } else {
            printf("0\n");
        }
    }
    printf("%d\n", a);
    return 0;
}