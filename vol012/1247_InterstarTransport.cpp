#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
int CharToInt(char c) {
	return ((int)c - 65);
}
char IntToChar(int i) {
	return (char)(i + 65);
}
void find_path(stack<int>&q, int t, vector<int>links) {
	if (t == -1) {
		return;
	}
	q.push(links[t]);
	find_path(q, links[t], links);
}
int main()
{
	vector<vector<ii>>graph;
	vector<int>distance;
	vector<int>acunodes;
	vector<int>links;
	graph = vector<vector<ii>>(26);
	int numplanets, p;
	scanf("%d %d", &numplanets, &p);
	for (int i = 0; i < p; i++) {
		char cu, cv;
		int u, v, w;
		fflush(stdin);
		scanf(" %c %c %d", &cu, &cv, &w);
		u = CharToInt(cu);
		v = CharToInt(cv);
		graph[u].push_back({ w,v });
		graph[v].push_back({ w,u });
	}
	int q;
	scanf("%d", &q);
	char cs, ct;
	int s, t;
	for (int i = 0; i < q; i++) {

		distance = vector<int>(26, -1);
		acunodes = vector<int>(26, -1);
		links = vector<int>(26, -1);
		scanf(" %c %c", &cs, &ct);
		s = CharToInt(cs);
		t = CharToInt(ct);
		priority_queue<ii, vector<ii>, greater<ii>>pq;
		distance[s] = 0;
		acunodes[s] = 1;
		pq.push({ 0,s });
		while (!pq.empty()) {
			int node = pq.top().second;
			int wnode = pq.top().first;
			pq.pop();
			if (distance[node] >= wnode) {
				for (int i = 0; i < graph[node].size(); i++) {
					int ad = graph[node][i].second;
					int wad = graph[node][i].first;
					int newweight = wnode + wad;
					if (distance[ad] == -1 || distance[ad] > newweight ||
						(distance[ad] == newweight && acunodes[node] + 1  < acunodes[ad])) {
						distance[ad] = newweight;
						acunodes[ad] = acunodes[node] + 1;
						links[ad] = node;
						pq.push({ newweight,ad });
					}
				}
			}
		}

		stack<int>q;
		q.push(t);
		find_path(q, t, links);
		q.pop();
		int ss = q.size();
		for (int i = 0; i < ss; i++) {
			auto aux = q.top(); q.pop();
			char aux2 = IntToChar(aux);
			if (i + 1 == ss) {
				printf("%c", aux2);
			}
			else {
				printf("%c ", aux2);

			}
		}
		printf("\n");
	}

	return 0;
}
