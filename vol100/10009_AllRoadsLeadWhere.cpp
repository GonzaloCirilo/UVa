#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>G;
char token[29];
vi visited, links;
void printer(int n) {
	if (n == -1)
		return;
	printer(links[n]);
	printf("%c", token[n]);
}
int main() {
	int t, q, m;
	scanf("%d", &t);
	char u[50], v[50];
	G graph;
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		map<char, int>dict;
		scanf("%d %d\n", &m, &q);
		int cont = 0;
		vector<pair<int, int>> edges;
		while (m) {
			scanf("%s %s\n", &u, &v);
			if (dict.insert({ u[0],cont }).second) {
				token[cont] = u[0];
				cont++;
			}
			if (dict.insert({ v[0],cont }).second) {
				token[cont] = v[0];
				cont++;
			}
			edges.push_back({ dict[u[0]],dict[v[0]] });
			m--;
		}
		graph = G(cont);
		for (int j = 0; j < edges.size(); j++) {
			auto aux = edges[j];
			graph[aux.first].push_back(aux.second);
			graph[aux.second].push_back(aux.first);
		}
		while (q) {
			scanf("%s %s\n", &u, &v);
			int s = dict[u[0]], t = dict[v[0]], finished = 0;
			visited = vi(cont, 0);
			links = vi(cont, -1);
			queue<pair<int,int>> que;
			que.push({ s,0 });
			visited[s] = 1;
			while (!que.empty() && !finished) {
				int n = que.front().first, d = que.front().second; que.pop();
				for (int j = 0; j < graph[n].size(); j++) {
					if (!visited[graph[n][j]]) {
						visited[graph[n][j]] = 1;
						links[graph[n][j]] = n;
						if (graph[n][j] == t) {
							finished = d+1;
							break;
						}							
						que.push({ graph[n][j],d + 1 });
						
					}
				}
			}
			printer(t);
			printf("\n");
			q--;
		}

	}
	return 0;
}