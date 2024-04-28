#include <stdio.h>

int main() {
    int t, n;
    char c;
    scanf("%d\n", &t);
    for (int i = 1; i <= t; i++) {
        scanf("%d\n", &n);
        printf("Case %d: ", i);
        int ls = 0; bool broken = false;
        for (int j = 1; j <= n; j++) {
            scanf("%c\n", &c);
            if (broken) continue;
            if (c == 'L' || c == 'D') {
                ls++;
            } else {
                ls = 0;
            }
            //printf("ev %c: %d\n", c, ls);
            if (ls == 3) {
                printf("%d\n", j);
                broken = true;
            }
        }
        if (ls < 3) {
            printf("Yay! Mighty Rafa persists!\n");
        }
    }
    return 0;
}