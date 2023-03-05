#include <stdio.h>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> graph;
int main() {
    printf("SHIPPING ROUTES OUTPUT\n");
    int t, m, n, p;
    scanf("%d\n", &t);

    for(int i = 1; i <= t; i++) {
        printf("\nDATA SET  %d\n\n", i);
        scanf("%d %d %d\n", &m, &n, &p);
        map<string, int> dict;
        graph g = graph(m);
        for(int j = 0; j < m; j++) {
            string token;
            cin >> token;
            dict[token] = j;
        }
        for (int j = 0; j < n; j++) {
            string token, token2;
            cin >> token >> token2;
            int u = dict[token], v = dict[token2];
			g[u].push_back(v);
            g[v].push_back(u);
        }

        for (int j = 0; j < p; j++) {
            int size;
            string token, token2;
            cin >> size >> token >> token2;
            int u = dict[token], v = dict[token2];
            // bfs
            queue<int> q;
            vi visited = vi(m, 0);
            visited[u] = 1;
            q.push(u);
            while(!q.empty()) {
				auto node = q.front(); q.pop();
                for (int k = 0; k < g[node].size(); k++) {
					int adj = g[node][k];
                    if (visited[adj] == 0) {
                        visited[adj] = visited[node] + 1;
                        q.push(adj);
                    }
                }
            }
            if (visited[v] == 0) {
                printf("NO SHIPMENT POSSIBLE\n");
            } else {
                printf("$%d\n", (visited[v] - 1) * size * 100);
            }
        }
    }
    printf("\nEND OF OUTPUT\n");
    return 0;
}