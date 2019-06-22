#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> G;
bool fastScan(int &x) {
	bool neg = false;
	int c;
	bool end = (c = getchar()) == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-'){
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
int main() {
	int n, m, u, v, ppa, max;
	G graph;
	vi visited, weight;
	vector<ii> posix;
	while (true) {
		fastScan(n);
		fastScan(m);
		if(!n && !m) break;
		max = -2147483648;
		graph = G(n);
		weight = vi();
		posix = vector<ii>();
		visited = vi(n, 0);
		for (int i = 0; i < m; i++) {
			//scanf("%d %d %d", &u, &v, &ppa);
			fastScan(u);
			fastScan(v);
			fastScan(ppa);
			max = max < ppa ? ppa : max;
			weight.push_back(ppa);
			posix.push_back({ u - 1,v - 1 });
		}
		for (int i = 0; i < m; i++) {
			if (weight[i] == max) {
				graph[posix[i].first].push_back(posix[i].second);
				graph[posix[i].second].push_back(posix[i].first);
			}
		}
		int ans = 0, cont;
		for (int i = 0; i < n; i++) {
			if (!visited[i]) {
				queue<int> q;
				visited[i] = 1;
				q.push(i);
				cont = 1;
				while (!q.empty()) {
					int aux = q.front(); q.pop();
					for (int i = 0; i < graph[aux].size(); i++) {
						int dest = graph[aux][i];
						if (!visited[dest]) {
							visited[dest] = 1;
							q.push(dest);
							cont++;
						}
					}
				}
				ans = ans < cont ? cont : ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}