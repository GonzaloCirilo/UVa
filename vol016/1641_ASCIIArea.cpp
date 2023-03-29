#include <stdio.h>

int main() {
    int h, w;
    while(scanf("%d %d\n", &h, &w) != EOF) {
        int ans = 0;
        for(int i = 0; i < h; i++) {
            bool opened = false;
            for(int j = 0; j < w; j++) {
                char c = getchar();
                if (c == '\\' || c == '/') {
                    opened = !opened;
                    ans++;
                } else {
                    if (opened) {
                        ans += 2;
                    }
                }
            }
            getchar();
        }
        printf("%d\n", ans / 2);
    }
    
    return 0;
}