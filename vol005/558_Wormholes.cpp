#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int>ii;
typedef vector<ii> vii;
typedef vector<vii>Gi;
Gi graph;
vector<int>distances;
int main()
{
	int cases;
	scanf("%distances", &cases);
	for (int c = 0; c < cases; c++) {
		int n, m;
		scanf("%distances %distances", &n, &m);
		graph = vector<vii>(n);
		distances = vector<int>(n, -1);
		for (int j = 0; j < m; j++) {
			int u, v, w;
			scanf("%distances %distances %distances", &u, &v, &w);
			graph[u].push_back({ v,w });
		}
		queue<ii>q;
		q.push({ 0,0 });
		distances[0] = 0;
		int cont = 0;
		while (!q.empty() && cont <= m) {
			int node = q.front().first;
			int wnode = q.front().second;
			q.pop();
			if (wnode <= distances[node]) {
				for (int i = 0; i < graph[node].size(); i++) {
					int ad = graph[node][i].first;
					int wad = graph[node][i].second;
					int newweight = wnode + wad;
					if (distances[ad] == -1 || newweight < distances[ad]) {
						distances[ad] = newweight;
						q.push({ ad,newweight });
						cont++;
					}

				}
			}
		}
		if (q.empty())printf("not possible\n"); else printf("possible\n");
	}
	return 0;
}
