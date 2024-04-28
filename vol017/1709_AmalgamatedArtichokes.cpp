#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;

double price(int p, int a, int b, int c, int d, int k) {
    return p * (sin(a * k + b) + cos(c * k + d) + 2);
}

int main() {
    int n, p, a, b, c, d;
    while (scanf("%d %d %d %d %d %d", &p, &a, &b, &c, &d, &n) != EOF) {
        double ans = 0, maxe = -1e9;
        for (int i = 1; i <= n; i++) {
            double x = price(p, a, b, c, d, i);
            if (x > maxe) {
                maxe = x;
            } else {
                ans = max(ans, maxe - x);
            }
        }
        printf("%.6lf\n", ans);
        
    }
    return 0;
}