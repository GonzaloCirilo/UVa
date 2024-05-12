#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

// calculates lis & lds
pair<int, int> lis(vector<int> h, vector<int> w) {
    vector<int> lis = vector<int>(h.size());
    vector<int> lds = vector<int>(h.size());
    lds[0] = w[0];
    lis[0] = w[0];

    for (int i = 1; i < h.size(); i++) {
        lis[i] = w[i];
        lds[i] = w[i];
        for (int j = 0; j < i; j++) {
            // lis
            if (h[i] > h[j] && lis[i] < lis[j] + w[i]) {
                lis[i] = lis[j] + w[i];
            }
            // lds
            if (h[i] < h[j] && lds[i] < lds[j] + w[i]) {
                lds[i] = lds[j] + w[i];
            }
        }
    }
    return { *max_element(lis.begin(), lis.end()), *max_element(lds.begin(), lds.end())};
}

int lds(vector<int> h, vector<int> w) {
    vector<int> lds = vector<int>(h.size());
    lds[0] = w[0];
 
    for (int i = 1; i < h.size(); i++) {
        lds[i] = w[i];
        for (int j = 0; j < i; j++)
            if (h[i] < h[j] && lds[i] < lds[j] + w[i])
                lds[i] = lds[j] + w[i];
    }
    return *max_element(lds.begin(), lds.end());
}

int main () {
    int t, n, x;
    scanf("%d", &t);
    for (int ti = 1; ti <= t; ti++) {
        printf("Case %d. ", ti);
        scanf("%d", &n);
        vector<int> h, w;
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            h.push_back(x);
        }
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            w.push_back(x);
        }
        auto ans = lis(h, w);
        int inc = ans.first, dec = ans.second;
        if (inc >= dec)
            printf("Increasing (%d).", inc);
        else 
            printf("Decreasing (%d).", dec);
        printf(" ");
        if (inc >= dec)
            printf("Decreasing (%d).", dec);
        else 
            printf("Increasing (%d).", inc);
        printf("\n");
    }
    return 0;
}
