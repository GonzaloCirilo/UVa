#include <stdio.h>
#include <vector>
using namespace std;
int p, r, bh, of, yh, m, u, v, w;
vector<int> visited;
vector<vector<int>> graphB, graphY;
void floydWarshall(vector<vector<int>> &graph) {
	for (int k = 0; k < p; k++) {
		if (visited[k])continue;
		for (int i = 0; i < p; i++) {
			if (visited[i])continue;
			for (int j = 0; j < p; j++) {
				if (visited[j])continue;
				if (graph[i][k] + graph[k][j] < graph[i][j])
					graph[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}
}
int main() {
	while (scanf("%d %d %d %d %d %d", &p, &r, &bh, &of, &yh, &m) != EOF) {
		bh--, of--, yh--, m--;
		graphB = vector<vector<int>>(p, vector<int>(p,10000000));
		visited = vector<int>(p, 0);
		for (int i = 0; i < p; i++)
			graphB[i][i] = 0;
		for (int i = 0; i < r; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			graphB[u][v] = w;
			graphB[v][u] = w;
		}
		graphY = graphB;
		floydWarshall(graphB);
		for (int i = 0; i <  p; ++i) {
			if (graphB[bh][of] == graphB[bh][i] + graphB[i][of]) visited[i] = 1;
		}
		floydWarshall(graphY);
		if (graphY[yh][m] == 10000000 || visited[m] || visited[yh])
			printf("MISSION IMPOSSIBLE.\n");
		else
			printf("%d\n", graphY[yh][m]);
	}
	return 0;
}