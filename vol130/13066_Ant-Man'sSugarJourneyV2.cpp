#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
G graph, tc;
vi set, visited;
int search(int s) {
	if (visited[s])
		return 0;
	visited[s] = 1;
	for (int i = 0; i <(int) graph[s].size(); i++) {
		if (set[graph[s][i]] == -1 || search(set[graph[s][i]])) {
			set[graph[s][i]] = s;
			return 1;
		}
	}
	return 0;
}
void transitive_closure(int s, int u, int depth) {
	tc[s][u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		if (!tc[s][graph[u][i]]) {
			if (depth > 1)
				graph[s].push_back(graph[u][i]);
			transitive_closure(s, graph[u][i], depth + 1);
		}
	}
}
int main() {
	int n, m, u, v;
	while (scanf("%d %d", &n, &m) != EOF) {
		graph = G(n); tc = G(n, vi(n, 0));
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		for (int i = 0; i < n; i++) {
			transitive_closure(i, i, 1);
		}
		int r = 0;
		set = vi(n, -1);
		for (int i = 0; i < n; i++) {
			visited = vi(n, 0);
			r += search(i);
		}
		printf("%d\n", n - r);
	}
	return 0;
}