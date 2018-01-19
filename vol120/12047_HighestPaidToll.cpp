#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
typedef vector<int>Vi;
typedef vector<ii>Vii;
typedef vector<Vii>G;
int main() {
	G graph, graph_rev;
	int test, n, m, s, t, p;
	Vi distances, distancet;
	scanf("%d", &test);
	for (int ts = 0; ts<test; ts++) {
		scanf("%d %d %d %d %d", &n, &m, &s, &t, &p);
		graph = G(n);
		graph_rev = G(n);
		s--; t--;
		priority_queue<iii, vector<iii>, less<iii>>edges;
		for (int i = 0; i<m; i++) {
			int u, v, c;
			scanf("%d %d %d", &u, &v, &c);
			u--; v--;
			graph[u].push_back({ c,v });
			graph_rev[v].push_back({ c,u });
			edges.push({ c,{u,v} });
		}
		//Djkstra from s
		priority_queue<ii, vector<ii>, greater<ii>>pq;
		distances = Vi(n, -1);
		pq.push({ 0,s });
		distances[s] = 0;
		while (!pq.empty()) {
			int nodo = pq.top().second;
			int wnodo = pq.top().first;
			pq.pop();
			if (distances[nodo] >= wnodo) {
				for (int i = 0; i < graph[nodo].size(); i++) {
					int adjacent = graph[nodo][i].second;
					int wadjacent = graph[nodo][i].first;
					int posiblew = wnodo + wadjacent;
					if ((distances[adjacent] == -1 || posiblew < distances[adjacent])) {
						distances[adjacent] = posiblew;
						pq.push({ posiblew,adjacent });
					}
				}
			}
		}
		//Djkstra from t
		distancet = Vi(n, -1);
		pq.push({ 0,t });
		distancet[t] = 0;
		while (!pq.empty()) {
			int nodo = pq.top().second;
			int wnodo = pq.top().first;
			pq.pop();
			if (distancet[nodo] >= wnodo) {
				for (int i = 0; i < graph_rev[nodo].size(); i++) {
					int adjacent = graph_rev[nodo][i].second;
					int wadjacent = graph_rev[nodo][i].first;
					int posiblew = wnodo + wadjacent;
					if ((distancet[adjacent] == -1 || posiblew < distancet[adjacent])) {
						distancet[adjacent] = posiblew;
						pq.push({ posiblew,adjacent });
					}
				}
			}
		}
		int ans = -1;
		while (!edges.empty()) {
			iii edge = edges.top(); edges.pop();
			if (distances[edge.second.first] == -1 || distancet[edge.second.second] == -1)continue;
			if (edge.first + distances[edge.second.first] + distancet[edge.second.second] <= p) {
				ans = edge.first; break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}