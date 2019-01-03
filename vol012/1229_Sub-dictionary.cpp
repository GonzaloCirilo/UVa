#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef vector<int>vi;
typedef vector<vi>G;
int main() {
	int n;
	char line[1000];
	set<string> def[100];
	string dict[1000];
	vi visited, visitedRev;
	stack<int> mainStack;
	G graph, revG;
	while (scanf("%d\n", &n) && n) {
		map<string, int>m;
		graph = G(n);
		revG = graph;
		visited = vi(n, 0);
		visitedRev = visited;
		for (int i = 0; i < n; i++) {
			def[i].clear();
			fgets(line, 1000, stdin);
			string s = string(line);
			s.erase(prev(s.end()));
			s.append(" ");
			int cont = 0;
			size_t start = 0, end = s.find(' ');
			while (end != string::npos) {
				string sub = s.substr(start, end - start);
				if (sub != "") {
					if (!cont) {
						m.insert({ sub,i });
						dict[i] = sub;
					}
					else {
						def[i].insert(sub);
					}
				}
				start = end + 1;
				end = s.find(' ', start);
				cont++;
			}
		}
		for (int i = 0; i < n; i++) {
			for (auto it = def[i].begin(); def[i].end() != it; it++) {
				graph[i].push_back(m[*it]);
				revG[m[*it]].push_back(i);
			}
		}
		//kosaraju
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
		int ans = 0; set<string>words;
		while (!mainStack.empty()) {
			int node = mainStack.top(); mainStack.pop();
			int cont = 1;
			set<string>ws;
			if (!visitedRev[node]) {
				stack<int> s;
				s.push(node);
				visitedRev[node] = 1;
				ws.insert(dict[node]);
				while (!s.empty()) {
					int n = s.top(); s.pop();
					for (int i = 0; i < revG[n].size(); i++) {
						if (!visitedRev[revG[n][i]]) {
							visitedRev[revG[n][i]] = 1;
							s.push(revG[n][i]);
							ws.insert(dict[revG[n][i]]);
							cont++;
						}
					}
				}
			}
			if (cont > 1) {
				ans += cont;
				words.insert(ws.begin(),ws.end());
			}
		}
		set<string>aux = words;
		visited = vi(n, 0);
		for (auto it = aux.begin(); it != aux.end(); it++) {
			int node = m[*it];
			if (!visited[node]) {
				queue<int> q;
				q.push(node);
				visited[node] = 1;
				while (!q.empty()) {
					int aux = q.front(); q.pop();
					for (int i = 0; i < graph[aux].size(); i++) {
						if (!visited[graph[aux][i]]) {
							if (words.insert(dict[graph[aux][i]]).second) {
								ans++;
							}
							visited[graph[aux][i]] = 1;
							q.push(graph[aux][i]);
						}
					}
				}
			}
			
		}
		printf("%d\n", ans);
		int cont = 0;
		for (auto it = words.begin(); it != words.end(); it++) {
			if (cont)
				printf(" ");
			printf("%s", (*it).c_str());
			cont++;
		}
		printf("\n");
	}
	return 0;
}