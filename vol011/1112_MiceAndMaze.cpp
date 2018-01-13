#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
int n, e, tl, m;
int u, v, t;
int cases;
int main()
{
	int c;
	scanf("%d", &c);
	for (cases = 0; cases < c; cases++) {
		vector<int>distances;
		vector<vector<ii>>graph;
		scanf("%d", &n);
		graph = vector<vector<ii>>(n);
		scanf("%d", &e); e--;
		scanf("%d", &tl);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &t);
			u--; v--;
			graph[u].push_back({ t,v });
		}
		int numEscp = 0;
		for (int s = 0; s<n; s++) {
			priority_queue<ii, vector<ii>, greater<ii>>pq;
			distances = vector<int>(n, -1);
			distances[s] = 0;
			pq.push({ 0,s });
			while (!pq.empty()) {
				int node = pq.top().second;
				int wnode = pq.top().first;
				pq.pop();
				if (distances[node] >= wnode) {
					for (int j = 0; j < graph[node].size(); j++) {
						int wad = graph[node][j].first;
						int ad = graph[node][j].second;
						int newweight = wnode + wad;
						if (distances[ad] == -1 || distances[ad] > newweight) {
							distances[ad] = newweight;
							pq.push({ newweight,ad });
						}
					}
				}
			}
			if (distances[e] <= tl && distances[e] != -1)numEscp++;
		}

		printf("%d\n", numEscp);
		if (cases != c - 1)printf("\n");

	}
	return 0;
}
