#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int>ii;
int n, e, tl, m;
int u, v, t;
int cases;
int main()
{
	int c;
	scanf("%d", &c);
	for (cases = 0; cases < c; cases++) {
		vector<int>distancia;
		vector<vector<ii>>grafo;
		scanf("%d", &n);
		grafo = vector<vector<ii>>(n);
		scanf("%d", &e); e--;
		scanf("%d", &tl);
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &t);
			u--; v--;
			grafo[u].push_back({ t,v });
		}
		int numEscp = 0;
		for(int s=0;s<n;s++){
			priority_queue<ii, vector<ii>, greater<ii>>pq;
			distancia = vector<int>(n, -1);
			distancia[s] = 0;
			pq.push({ 0,s });
			while (!pq.empty()) {
				int nodo = pq.top().second;
				int pesonodo = pq.top().first;
				pq.pop();
				if (distancia[nodo] >= pesonodo) {
					for (int j = 0; j < grafo[nodo].size(); j++) {
						int pesoadya = grafo[nodo][j].first;
						int adyacente = grafo[nodo][j].second;
						int posiblepeso = pesonodo + pesoadya;
						if (distancia[adyacente] == -1 || distancia[adyacente] > posiblepeso) {
							distancia[adyacente] = posiblepeso;
							pq.push({ posiblepeso,adyacente });
						}
					}
				}
			}
			if (distancia[e] <= tl && distancia[e]!=-1)numEscp++;
		}

		printf("%d\n", numEscp);
		if (cases != c - 1)printf("\n");

	}
    return 0;
}
