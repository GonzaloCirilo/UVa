#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int main() {
	int n, u, v, nq, q;
	G graph;
	while (scanf("%d", &n) && n) {
		graph = G(n);
		while (scanf("%d", &u) && u) {
			while (scanf("%d", &v) && v) {
				graph[u - 1].push_back(v - 1);
			}
		}
		scanf("%d", &nq);
		while (nq) {
			scanf("%d", &q);
			vi visited = vi(n, 0);
			queue<int>qu;
			qu.push(q - 1);
			int cont = 0;
			while (!qu.empty()) {
				int node = qu.front(); qu.pop();
				for (int i = 0; i < graph[node].size(); i++) {
					if (!visited[graph[node][i]]) {
						cont++;
						visited[graph[node][i]] = 1;
						qu.push(graph[node][i]);
					}
				}
			}
			printf("%d", n - cont);
			for (int i = 0; i < n; i++) {
				if(!visited[i])
					printf(" %d", i + 1);
			}
			printf("\n");
			nq--;
		}
	}
	return 0;
}