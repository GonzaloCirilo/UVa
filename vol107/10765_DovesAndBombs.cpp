#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<vi> graph;

vi times, low, visited;
int t;
graph g;
vector<ii> ans;

void DFS(int u, int p) {
    visited[u] = 1;
    times[u] = t++;
    low[u] = times[u];
    for (int i = 0; i < g[u].size(); i++) {
        int v = g[u][i];
        //if (v == p) continue;
        if (!visited[v]) {
            DFS(v, u);
            low[u] = min(low[u], low[v]);
            if (low[v] >= times[u]) {
                //printf("ap for %d\n", v);
                ans[u].second++;
            }
        } else if (u != p) {
            low[u] = min(low[u], times[v]);
        } 
    }
    if (p == -1) {
        --ans[u].second;
    }
}

int main() {
    int n, m, x, y;
    while(scanf("%d %d", &n, &m) && n != 0 && m != 0) {
        ans = vector<ii>();
        g = graph(n);
        while (true) {
            scanf("%d %d", &x, &y);
            if (x == -1 && y == -1) break;
            g[x].push_back(y);
            g[y].push_back(x);
        }
        t = 0;
        visited = vi(n, 0);
        times = vi(n, -1);
        low = vi(n, -1);
        ans = vector<ii>(n, {0,0});
        for (int i = 0; i < n; i++) {
            ans[i] = {i, 1};
        }
        for (int  i = 0; i < n; i++) {
            if (!visited[i]) {
                DFS(i, -1);
            }
        }
        sort(ans.begin(), ans.end(), [](ii l, ii r){
            if (l.second == r.second) return l.first< r.first;
            return l.second > r.second;
        });
        for (int i = 0; i < m; i++) {
            printf("%d %d\n", ans[i].first, ans[i].second);
        }
        printf("\n");
        
    }
    return 0;
}