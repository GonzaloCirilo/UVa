#include <stdio.h>
#include <math.h>
#include <stdint.h>
#include <vector>
using namespace std;
typedef pair<int,int> ii;
typedef pair<ii, long long> iill;

long long weight(int bv, int bu) {
    //printf("(%d - %d) ^ 3 = %lld\n", bv, bu, (long long)pow(bv - bu, 3));
    return pow(bv - bu, 3);
}

int main() {
    int infinity = 1e9;
    int n, count = 1, x, p, u, v, q;
    while (scanf("%d", &n) == 1) {
        vector<int> arr;
        printf("Set #%d\n", count++);

        
        for (int i = 0; i < n; i++) {
            scanf("%d", &x);
            arr.push_back(x);
        }
        
        scanf("%d", &p);
        vector<iill> edges;
        while (p--) {
            scanf("%d %d", &u, &v);
            edges.push_back({{u-1, v-1}, weight(arr[v-1], arr[u-1])});
        }
        scanf("%d", &q);
        if (n > 0) {
            // bell-ford
            vector<int> dist = vector<int>(n, infinity);
            dist[0] = 0;

            for (int i = 1; i < n; i++) {
                for (int j = 0; j < edges.size(); j++) {
                    int eu = edges[j].first.first, ev = edges[j].first.second;
                    long long w = edges[j].second;
                    if (dist[eu] != infinity && dist[eu] + w < dist[ev]) {
                        dist[ev] = dist[eu] + w;
                    } 
                }
            }
            // Check for negative cycles
            for (int j = 0; j < edges.size(); j++) {
                int eu = edges[j].first.first, ev = edges[j].first.second;
                    long long w = edges[j].second;
                    if (dist[eu] != infinity && dist[eu] + w < dist[ev]) { // cycle
                        dist[ev] = -1e9;
                    } 
            }
            while(q--) {
                scanf("%d", &x);
                int ans = dist[x-1];
                if (ans < 3 || ans == infinity) {
                    printf("?\n");
                } else {
                    printf("%d\n", ans);
                }
            }
        }
    }
    return 0;
}