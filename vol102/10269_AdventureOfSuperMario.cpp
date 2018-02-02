#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
struct Node {
	int index, actk, w;
	Node() {};
	Node(int _index, int _actk, int _w) {
		index = _index; actk = _actk; w = _w;
	}
	bool operator ()(const Node& a, const Node& b) {
		return a.w > b.w;
	}
};
int main() {
	int ta, a, b, m, l, k, x, y, c, inf = 9999999;
	vvi graph, distances;
	scanf("%d", &ta);
	for (int t = 0; t < ta; t++) {
		scanf("%d %d %d %d %d", &a, &b, &m, &l, &k);
		graph = vvi(a + b, vi(a + b, inf));
		distances = vvi(a + b, vi(k + 1, inf));
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &x, &y, &c);
			x--; y--;
			graph[y][x] = c;
			graph[x][y] = c;
		}
		if (t == 20)
			c = 0;
		//Floyd warshall
		for (int x = 0; x < a; x++) {
			for (int i = 0; i < a + b; i++) {
				for (int j = 0; j < a + b; j++) {
					if (graph[i][x] + graph[x][j] < graph[i][j])
						graph[i][j] = graph[i][x] + graph[x][j];
				}
			}
		}
		//Dijkstra
		priority_queue<Node, vector<Node>, Node>pq;
		pq.push(Node(a + b - 1, k, 0));
		while (!pq.empty()) {
			Node n = pq.top(); pq.pop();
			if (distances[n.index][n.actk] == inf) {
				distances[n.index][n.actk] = n.w;
				for (int i = 0; i < a + b; i++) {
					if (graph[n.index][i] != inf && distances[i][n.actk] == inf)
						pq.push(Node(i, n.actk, n.w + graph[n.index][i]));
					if (n.actk > 0 && graph[n.index][i] <= l && distances[i][n.actk - 1] == inf)
						pq.push(Node(i, n.actk - 1, n.w));
				}
			}
		}
		printf("%d\n", *min_element(distances[0].begin(),distances[0].end()));
	}
	return 0;
}
