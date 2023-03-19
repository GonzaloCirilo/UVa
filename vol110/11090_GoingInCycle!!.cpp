#include <vector>
#include <stdio.h>
#include <algorithm>
using namespace std;
typedef vector<int>vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<vii> graph;
typedef vector<vi> matrix;
graph g;
vi visited;
vector<double> pos;

bool dfs(int ind, vi stack) {
    if (visited[ind] == 1) {
        return true;
    }

    visited[ind] = 1;

    for (int i = 0; i < g[ind].size(); i++) {
        ii adj = g[ind][i];
        //printf("loop ind %d adj %d\n", ind, adj.first);
        stack.push_back(adj.first);
        auto ans = dfs(adj.first, stack);
        if (ans)
            return true;
        stack.pop_back();
    }
    return false;
}

int main(){
    int t, n, m, a, b, c;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++) {
        printf("Case #%d: ", i);
        scanf("%d %d", &n, &m);

        graph aux = graph(n);
        g = graph();
        for (int j = 0; j < m; j++) {
            scanf("%d %d %d", &a, &b, &c);
            a--, b--;
            aux[a].push_back({b, c});
        }

        // reduce graph?
        for(int j = 0; j < n; j++) {
            sort(aux[j].begin(), aux[j].end());
            vii reduced = vii(); 
            int taken[51] = {};
            for(int k = 0; k < aux[j].size(); k++) {
                if(!taken[aux[j][k].first]){
                    reduced.push_back(aux[j][k]);
                    taken[aux[j][k].first] = 1;
                }
            }
            g.push_back(reduced);
        }

        // karps min mean cycle
        matrix dp = matrix(n+1);
        for (int j = 0; j < dp.size(); j++) {
            dp[j] = vi(n, -1);
        }

        for(int j = 0; j < n; j++) {
            dp[0][j] = 0;
        }

        for (int j = 1; j <= n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < g[k].size(); l++) {
                    //printf("\n||checking %d %d", j-1,g[k][l].first);
                    if (dp[j-1][g[k][l].first] != -1) {
                        int w = dp[j-1][g[k][l].first] + g[k][l].second;
                        //printf("\n||preparing w %d", w);
                        if (dp[j][k] == -1) {
                            dp[j][k] = w;
                            //printf("\n||dp j k is now %d", w);
                        } else {
                            dp[j][k] = min(dp[j][k], w);
                        }
                    }
                }
            }
        }

        vector<double> avgs = vector<double>(n, -1);

        for (int j = 0; j < n; j++) {
            if (dp[n][j] != -1) {
                for (int k = 0; k < n; k++) {
                    if (dp[k][j] != -1) {
                        avgs[j] = max(avgs[j], (dp[n][j] - dp[k][j]) * 1.0 / (n-k));
                    }
                }
            }
        }

        // check if has cycles
        visited = vi(n, 0);
        pos = vector<double>();
        bool hasCycle = false;
        for (int j = 0; j < n; j++) {
            if (!visited[j]) {
                vi s = vi();
                s.push_back(j);
                hasCycle |= dfs(j, s);
            }
        }
        double ans = 1e9;
        for(int j = 0; j < avgs.size(); j++) {
            double x = avgs[j];
            if (x != -1 && x < ans) {
                ans = x;
            }
        }
        if (!hasCycle || ans == 1e9) {
            printf("No cycle found.\n");
        } else {
            printf("%.2lf\n", ans);
        }

    }
    return 0;
}