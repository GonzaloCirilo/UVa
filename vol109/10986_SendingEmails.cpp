#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
int main()
{
	vector<vector<ii>>grafo;
	vector<int>distancia;
	int c;
	scanf("%d", &c);
	for (int caso = 0;caso < c;caso++) {
		
		grafo.clear();
		distancia.clear();
		int n, m, s, t;
		scanf("%d %d %d %d", &n, &m, &s, &t);
		grafo = vector<vector<ii>>(n);
		distancia = vector<int>(n, -1);
		for (int i = 0;i < m;i++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			grafo[u].push_back({ w,v });
			grafo[v].push_back({ w,u });
		}
		priority_queue<ii, vector<ii>, greater<ii>>cola;
		distancia[s] = 0;
		cola.push({ 0,s });
		while (!cola.empty()) {
			int nodo = cola.top().second;
			int pesonodo = cola.top().first;
			cola.pop();
			if (distancia[nodo] >= pesonodo) {
				for (int i = 0; i < grafo[nodo].size(); i++) {
					int adyacente = grafo[nodo][i].second;
					int peso = grafo[nodo][i].first;
					int posiblepeso = pesonodo + peso;
					if (distancia[adyacente] == -1 || distancia[adyacente] > posiblepeso) {
						distancia[adyacente] = posiblepeso;
						cola.push({ posiblepeso,adyacente });
					}

				}
			}
		}
		printf("Case #%d: ", caso+1);
		distancia[t] == -1 ? printf("unreachable\n") : printf("%d\n", distancia[t]);
	}
    return 0;
}
