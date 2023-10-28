#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        int x;
        int ans = -1e9;
        int currentMax;
        scanf("%d", &currentMax);
        for(int i = 1; i < n; i++) {
            scanf("%d", &x);
            ans = max(ans, currentMax-x);
            currentMax = max(currentMax, x);
        }
        printf("%d\n", ans);
        
    }
}