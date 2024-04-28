#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> cards = {1, 10, 100, 1000, 10000};

int evaluateMax(vector<int> arr, int b) {
    int sum = 0;
    for (int i = 1; i < arr.size(); i++) {
        sum += arr[i];
    }
    int maxe = 0;
    if (sum + arr[0] <= b) {
        maxe = arr[0];
    }
    for (int i = 0; i < cards.size(); i++) {
        if (cards[i] == arr[0]) continue;
        if (cards[i] + sum <= b) {
            maxe = max(maxe, cards[i]);
        }
    }
    int ans = maxe;
    if (sum + arr[0] <= b) {
        ans = maxe - arr[0];
    }
    //printf("===%d %d %d\n", ans, maxe, arr[0]);
    return ans;
}

int main() {
    int n, m, b, c;
    while (scanf("%d %d", &n, &m) != EOF) {
        int ans = 0;
        for (int j = 0; j < m; j++) {
            scanf("%d", &b);
            vector<int> arr;
            for (int i = 0; i < n; i++) {
                scanf("%d", &c);
                arr.push_back(c);
            }
            ans += evaluateMax(arr, b);
        }
        printf("%d\n", ans);

    }
    return 0;
}