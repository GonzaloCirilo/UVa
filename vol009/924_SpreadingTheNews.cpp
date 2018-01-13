#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int>Vi;
typedef vector<Vi>Gi;
Gi graph;
Vi distances;
int e, m, u, c, vstart;
Vi day;
Vi people;
void BFS(int nodo) {
	queue<int> q;
	q.push(nodo);
	distances[nodo] = 0;
	people[0] = 0;
	while (!q.empty()) {
		int actual = q.front(); q.pop();
		for (int i = 0; i < graph[actual].size(); i++) {
			int adyacente = graph[actual][i];
			if (distances[adyacente] < 0) {
				distances[adyacente] = distances[actual] + 1;
				int day = distances[adyacente];
				people[day] += 1;
				q.push(adyacente);
			}
		}
	}
}
int main()
{
	scanf("%d", &e);
	graph = Gi(e);

	for (int i = 0; i < e; i++) {
		scanf("%d ", &m);
		for (int j = 0; j < m; j++) {
			scanf("%d ", &u);
			graph[i].push_back(u);
		}
	}
	scanf("%d", &c);
	for (int j = 0; j < c; j++) {
		scanf("%d", &vstart);
		distances = Vi(e, -1);
		people = Vi(e, 0);
		BFS(vstart);
		int mDay = 0;
		int boomEmp = people[0];
		for (int i = 1; i < e; i++) {
			if (boomEmp < people[i]) {
				mDay = i;
				boomEmp = people[i];
			}
		}
		if (mDay == 0)
			printf("0\n");
		else {
			printf("%d %d\n", boomEmp, mDay);
		}
	}
	return 0;
}
