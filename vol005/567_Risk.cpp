#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int>Vi;
typedef vector<Vi>G;
G graph;
int BFS(int s, int t) {
	queue<pair<int, int>>q;
	q.push({ s,0 });
	while (!q.empty()) {
		int r = q.front().first, w = q.front().second;
		q.pop();
		for (int i = 0; i<graph[r].size(); i++) {
			int d = graph[r][i];
			if (d == t)
				return w + 1;
			q.push({ d,w + 1 });
		}
	}
	return 0;
}
int main() {
	int cont = 0, n, region, t = 1;
	graph = G(20);
	while (scanf("%d ", &n) != EOF) {
		for (int i = 0; i < n; i++) {
			scanf("%d ", &region);
			region--;
			graph[cont].push_back(region);
			graph[region].push_back(cont);
		}
		if (cont == 18) {
			int n, a, b;
			printf("Test Set #%d\n", t);
			scanf("%d", &n);
			for (int j = 0; j < n; j++) {
				scanf("%d %d", &a, &b);
				a--, b--;
				printf("%2d to %2d: %d\n", a + 1, b + 1, BFS(a, b));
			}
			printf("\n");
			graph = G(20);
			cont = 0;
			t++;
			continue;
		}
		cont++;
	}
	return 0;
}