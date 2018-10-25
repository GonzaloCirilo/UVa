#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> g;
int main() {
	int n; char token[3];
	char stringy[4];
	g graph;
	vector<bool> visited;
	scanf("%d\n", &n);
	for (int i = 0; i < n; i++) { 
		if (i > 0)
			printf("\n");
		fgets(token, 3, stdin);
		int t = (int)token[0] - 65;
		graph = g(t + 1);
		visited = vector<bool>(t + 1,0);
		while (fgets(stringy, 4, stdin) && stringy[0] != '\n') {
			int u = (int)stringy[0] - 65, v = (int)stringy[1] - 65;
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		int ans = 0;
		for (int j = 0; j <= t; j++) {
			//bfs
			if (!visited[j]) {
				queue<int> q;
				q.push(j);
				visited[j] = true;
				while (!q.empty()) {
					int o = q.front(); q.pop();
					for (int k = 0; k < graph[o].size(); k++) {
						if (!visited[graph[o][k]]) {
							visited[graph[o][k]] = true;
							q.push(graph[o][k]);
						}
					}
				}
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}