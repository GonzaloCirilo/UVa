#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
G bigraph, auxBigraph, graph, tc;
vi set;
stack<pair<int, int>> s;
int cont;
bool bfs(int n) {
	auxBigraph = G(2 * n);
	queue<int> q;
	for (int i = 0; i < n; i++) {
		if (set[i] == -1)
			q.push(i);
	}
	bool ans = false;
	vi visited = vi(2 * n, 0);
	s = stack<pair<int, int>>();
	while (!q.empty()) {
		int node = q.front(); q.pop();
		if (node >= n) {
			if (set[node] == -1) {
				ans = true;
				if (!visited[node])
					s.push({ node, -1 });
			}
			else {
				if (!visited[set[node]])
					q.push(set[node]);
				auxBigraph[set[node]].push_back(node);
			}
		}
		else {
			for (int i = 0; i < bigraph[node].size(); i++) {
				if (set[node] != bigraph[node][i]) {
					if (!visited[bigraph[node][i]])
						q.push(bigraph[node][i]);
					auxBigraph[bigraph[node][i]].push_back(node);
				}
			}
		}
		visited[node] = true;
	}
	return ans && !s.empty();
}
int dfs(int n) {
	int ans = 0;
	vi visited = vi(2 * n, 0);
	while (!s.empty()) {//s has values gretear than n before 1st iteration
		int node = s.top().first, prev = s.top().second; s.pop();
		if (set[node] == -1 && node < n) {
			ans += 1;
		}
		if (prev != -1) {
			if (node >= n && prev != -1) {
				set[node] = -1;
				auxBigraph[prev] = vi();

			}
			else {
				set[prev] = node;
				set[node] = prev;
				auxBigraph[prev] = vi();
			}
		}
		for (int i = 0; i < auxBigraph[node].size(); i++) {
			if (!visited[auxBigraph[node][i]]) {
				s.push({ auxBigraph[node][i],node });
				break;
			}
		}
		visited[node] = 1;
	}
	return ans;
}
void transitive_closure(int s, int u) {
	tc[s][u] = true;
	for (int i = 0; i < graph[u].size(); i++) {
		if (!tc[s][graph[u][i]])
			transitive_closure(s, graph[u][i]);
	}
}
int main() {
	int n, m, u, v;
	while (scanf("%d %d", &n, &m) != EOF) {
		bigraph = G(2 * n), graph = G(n), tc = G(n, vi(n, 0));
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
		}
		for (int i = 0; i < n; i++) {
			transitive_closure(i, i);
		}
		for (int i = 0; i < n; i++) {//Creating bipartite graph
			for (int j = 0; j < n; j++) {
				if (i != j && tc[i][j]) {
					bigraph[i].push_back(j + n);
					bigraph[j + n].push_back(i);
				}
			}
		}
		set = vi(2 * n, -1);//Hopcroft-Karp
		int ans = 0;
		while (bfs(n)) {
			ans += dfs(n);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}