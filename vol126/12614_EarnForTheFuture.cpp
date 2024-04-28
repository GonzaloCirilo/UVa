#include <stdio.h>

int main() {
    int t, n, c, counter = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int max = 0;
        while (n--) {
            scanf("%d", &c);
            if (c > max) {
                max = c;
            }
        }
        printf("Case %d: %d\n", counter++, max);
    }
    return 0;
}