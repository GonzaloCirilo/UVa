#include <stdio.h>
#include <math.h>

int main() {
    int n, i, j;
    while(scanf("%d %d %d", &n, &i, &j) != EOF) {
        int ans = 0;
        while (i != j) {
            i = ceil(i * 1.0 / 2);
            j = ceil(j * 1.0 / 2);
            //printf("=%d %d\n", i, j);
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}