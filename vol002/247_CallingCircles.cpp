#include <stdio.h>
#include <map>
#include <stack>
#include <queue>
#include <set>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> G;
int main() {
	int n, m;
	char u[26], v[26];
	G graph, rev;
	vi visited;
	string names[26];
	int t = 1;
	while (scanf("%d %d", &n, &m) && n) {
		if (t != 1)
			printf("\n");
		printf("Calling circles for data set %d:\n", t);
		graph = G(n);
		rev = graph;
		visited = vi(n, 0);
		map<string, int> dict;
		stack<int> mainStack;
		int cont = 0;
		for (int i = 0; i < m; i++) {
			scanf("%s %s", &u, &v);
			if (dict.find(u) == dict.end()) {
				dict.insert({ string(u),cont });
				names[cont] = string(u);
				cont++;
			}
			if (dict.find(v) == dict.end()) {
				dict.insert({ string(v),cont });
				names[cont] = string(v);
				cont++;
			}
			graph[dict[u]].push_back(dict[v]);
			rev[dict[v]].push_back(dict[u]);
		}
		set<int> sets;
		for (int i = 0; i < n; i++) {
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
		visited = vi(n, 0);
		while (!mainStack.empty()) {
			int node = mainStack.top(); mainStack.pop();
			if (!visited[node]) {
				stack<int>s;
				s.push(node);
				visited[node] = 1;
				printf("%s", names[node].c_str());
				while (!s.empty()) {
					int n = s.top(); s.pop();
					for (int i = 0; i < rev[n].size(); i++) {
						if (!visited[rev[n][i]]) {
							visited[rev[n][i]] = 1;
							s.push(rev[n][i]);
							printf(", %s", names[rev[n][i]].c_str());
						}
					}
				}
				printf("\n");
			}
		}
		t++;
	}
	return 0;
}