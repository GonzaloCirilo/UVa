#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>G;
int main() {
	int p, t, u, v;
	char token[30];
	vi visited, visitedRev;
	stack<int> mainStack;//to store topological order
	G graph, revG;
	while (scanf("%d %d\n", &p, &t) && p) {
		map<string, int>m;
		graph = G(p);
		revG = graph;
		visited = vi(p, 0);
		visitedRev = visited;
		for (int i = 0; i < p; i++) {
			fgets(token, 30, stdin);
			m.insert({ string(token),i });
		}
		for (int i = 0; i < t; i++) {
			fgets(token, 30, stdin);
			u = m[token];
			fgets(token, 30, stdin);
			v = m[token];
			graph[u].push_back(v);
			revG[v].push_back(u);
		}
		set<int> sets;
		for (int i = 0; i < p; i++) {
			if (!visited[i]) {
				stack<int> s;
				s.push(i);
				while (!s.empty()) {
					int node = s.top(); s.pop();
					if (visited[node]) {
						if (sets.find(node) == sets.end()) {
							sets.insert(node);
							mainStack.push(node);
						}
						continue;
					}
					visited[node] = true;
					s.push(node);
					for (int j = 0; j < graph[node].size(); j++) {
						if (!visited[graph[node][j]]) {
							s.push(graph[node][j]);
						}
					}
				}
			}
		}
		int ans = 0;
		while (!mainStack.empty()) {
			int node = mainStack.top(); mainStack.pop();
			int cont = 1;
			if (!visitedRev[node]) {
				ans++;
				stack<int> s;
				s.push(node);
				visitedRev[node] = 1;
				while (!s.empty()) {
					int n = s.top(); s.pop();
					for (int i = 0; i < revG[n].size(); i++) {
						if (!visitedRev[revG[n][i]]) {
							visitedRev[revG[n][i]] = 1;
							s.push(revG[n][i]);
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}