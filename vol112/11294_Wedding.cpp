#include <stdio.h>
#include <vector>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef vector<pair<int, int>>vii;
typedef vector<vi> G;
vi visited; vii answer;
G graph, revgraph;
stack<int> s, rs;
void DFS(int node)
{
	visited[node] = true;
	for (int i = 0; i < graph[node].size(); i++)
	{
		int ad = graph[node][i];
		if (visited[ad] == false)
			DFS(ad);
		ad = 0;
	}
	s.push(node);
}
void DFSRev(int node)
{
	visited[node] = true;
	for (int i = 0; i < revgraph[node].size(); i++)
	{
		int ad = revgraph[node][i];
		if (visited[ad] == false)
			DFSRev(ad);
	}
	rs.push(node);
}
int main() {
	int n, m, c1, c2, w, x, y, z;
	char s1[3], s2[3];
	while (true) {
		scanf("%d %d", &n, &m);
		graph = G(2 * n);
		revgraph = G(2 * n);
		visited = vi(2 * n, 0);
		answer = vii(n, { -1,0 });
		if (n == 0 && m == 0)break;
		for (int i = 0; i < m; i++) {
			scanf("%d%s %d%s", &c1, &s1, &c2, &s2);
			w = c1 * 2 + (s1[0] == 'w');
			y = c1 * 2 + !(s1[0] == 'w');
			x = c2 * 2 + (s2[0] == 'w');
			z = c2 * 2 + !(s2[0] == 'w');
			graph[w].push_back(z);
			graph[x].push_back(y);
			revgraph[z].push_back(w);
			revgraph[y].push_back(x);
		}
		for (int i = 0; i < 2 * n; i++) {
			if (!visited[i])
				DFS(i);
		}
		bool badluck = false;
		visited = vi(2 * n, 0);
		int nscc = 1;
		while (!s.empty()) {
			if (!visited[s.top()])
				DFSRev(s.top());
			s.pop();
			while (!rs.empty()) {
				int in = rs.top();
				if (in % 2 != 0)
					in -= 1;
				in /= 2;
				if (answer[in].second == nscc && answer[in].first != -1) {
					badluck = true;
					break;
				}
				answer[in] = { rs.top() % 2 == 0,nscc };
				rs.pop();
			}
			nscc++;
		}
		if (badluck || !answer[0].first)
			printf("bad luck");
		else {
			for (int i = 1; i < answer.size(); i++) {
				if (i != 1)
					printf(" ");
				printf("%d%s", i, answer[i].first ? "w" : "h");
			}
		}
		printf("\n");
	}
	return 0;
}
