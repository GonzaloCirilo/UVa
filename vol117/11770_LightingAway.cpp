#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int main() {
	int t,n, m, u, v; G graph;
	vi visited, visitedRev;
	stack<int> mainStack;//to store topological order
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &n, &m);
		graph = G(n);
		visited = vi(n, 0);
		visitedRev = visited;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			graph[u-1].push_back(v-1);
		}
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				stack<int> s;
				s.push(i);
				while (!s.empty()) {
					int node = s.top(); s.pop();
					if (visited[node]) {
						mainStack.push(node);
						continue;
					}
					visited[node] = true;
					s.push(node);
					for (int j = 0; j < graph[node].size(); j++) {
						if (!visited[graph[node][j]]) {
							s.push(graph[node][j]);
						}
					}
				}
			}
		}
		int ans = 0;
		while (!mainStack.empty()) {
			int node = mainStack.top(); mainStack.pop();
			int cont = 1;
			if (!visitedRev[node]) {
				ans++;
				stack<int> s;
				s.push(node);
				visitedRev[node] = 1;
				while (!s.empty()) {
					int n = s.top(); s.pop();
					for (int i = 0; i < graph[n].size(); i++) {
						if (!visitedRev[graph[n][i]]) {
							visitedRev[graph[n][i]] = 1;
							s.push(graph[n][i]);
						}
					}
				}
			}
		}
		printf("Case %d: %d\n", i, ans);
	}
	return 0;
}