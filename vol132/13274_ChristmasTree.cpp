#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
//int cont = 0;
G graph;
vector<bool>visited;
int dfs(int k, int s, int actual) {
	if (graph[actual].size() - 1 < k)
		return 1;
	vector<int> nodes;
	for (auto child : graph[actual]) {
		if (child != s) {
			nodes.push_back(dfs(k, actual, child));
		}
	}
	int ans = 1;
	sort(nodes.rbegin(), nodes.rend());
	for (int i = 0; i < k; i++) {
		ans += nodes[i];
	}
	return ans;
}

int main() {
	int t, n, k, u, v;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &n, &k);
		graph = G(n+1);
		graph[1].push_back(0);
		for (int j = 0; j < n-1; j++) {
			scanf("%d %d", &u, &v);
			graph[u].push_back(v);
			graph[v].push_back(u);
		}
		printf("Case %d: %d\n", i, dfs(k, 0, 1));
	}
	return 0;
}