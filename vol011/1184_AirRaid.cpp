#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
G graph;
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
int main() {
	int n, m, u, v, t;
	scanf("%d", &t);
	while (t) {
		scanf("%d %d", &n, &m);
		graph = G(n);
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &u, &v);
			graph[u - 1].push_back(v - 1);
		}
		int r = 0;
		set = vi(n, -1);
		for (int i = 0; i < n; i++) {
			visited = vi(n, 0);
			r += search(i);
		}
		
		printf("%d\n", n - r);
		t--;
	}
	return 0;
}