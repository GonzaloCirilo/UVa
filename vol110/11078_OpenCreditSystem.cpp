#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        vector<int> arr = vector<int>();
        int x;
        for(int i = 0; i < n; i++) {
            scanf("%d", &x);
            arr.push_back(x);
        }
        int ans = -1e9;
        int currentMax = arr[0];
        for (int i = 1; i < n; i++) {
            ans = max(ans, currentMax-arr[i]);
            currentMax = max(currentMax, arr[i]);
        }
        printf("%d\n", ans);
        
    }
}