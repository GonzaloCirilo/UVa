#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
struct Node {
	int to, a, b, t;
};
typedef vector<Node> vi;
typedef vector<vi> G;
int main() {
	G graph;
	int n, m, s, t, u, cont = 1;
	Node v;
	vector<int> distances;
	while (scanf("%d %d %d %d", &n, &m, &s, &t) != EOF) {
		graph = G(n + 1);
		distances = vector<int>(n + 1, -1);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d %d %d", &u, &v.to, &v.a, &v.b, &v.t);
			graph[u].push_back(v);
		}
		priority_queue<ii, vector<ii>, greater<ii>>pq;
		pq.push({ 0,s });
		distances[s] = 0;
		while (!pq.empty()) {
			ii node = pq.top(); pq.pop();
			if(distances[node.second] >= node.first){
				for (int i = 0; i < graph[node.second].size(); i++) {
					Node e = graph[node.second][i];
					if (e.a < e.t)continue;
					int newWeight = (node.first % (e.a + e.b) + e.t > e.a)*(e.a + e.b - node.first % (e.a + e.b)) + e.t + node.first;
					if (distances[e.to] == -1 || distances[e.to] > newWeight) {
						distances[e.to] = newWeight;
						pq.push({ newWeight,e.to });
					}
				}
			}
		}
		printf("Case %d: %d\n", cont, distances[t]);
		cont++;
	}
}