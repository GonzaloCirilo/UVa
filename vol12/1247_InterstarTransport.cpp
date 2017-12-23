#include <stdio.h>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
int convertCharToInt(char c) {
	return ((int)c - 65);
}
char convertIntToChar(int i) {
	return (char)(i + 65);
}
void poner_respuestas(stack<int>&q, int t, vector<int>links) {
	if (t == -1) {
		return;
	}
	q.push(links[t]);
	poner_respuestas(q, links[t], links);
}
int main()
{
	vector<vector<ii>>grafo;
	vector<int>distancia;
	vector<int>nodosAc;
	vector<int>links;
	grafo = vector<vector<ii>>(26);
	int numplanets, p;
	scanf("%d %d", &numplanets, &p);
	for (int i = 0; i < p; i++) {
		char cu, cv;
		int u, v, w;
		fflush(stdin);
		scanf(" %c %c %d", &cu, &cv, &w);
		u = convertCharToInt(cu);
		v = convertCharToInt(cv);
		grafo[u].push_back({ w,v });
		grafo[v].push_back({ w,u });
	}
	int q;
	scanf("%d", &q);
	char cs, ct;
	int s, t;
	for (int i = 0; i < q; i++) {

		distancia = vector<int>(26, -1);
		nodosAc = vector<int>(26, -1);
		links = vector<int>(26, -1);
		scanf(" %c %c", &cs, &ct);
		s = convertCharToInt(cs);
		t = convertCharToInt(ct);
		priority_queue<ii, vector<ii>, greater<ii>>cola;
		distancia[s] = 0;
		nodosAc[s] = 1;
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
					if (distancia[adyacente] == -1 || distancia[adyacente] > posiblepeso || 
						(distancia[adyacente] == posiblepeso && nodosAc[nodo]+1  < nodosAc[adyacente])) {
						distancia[adyacente] = posiblepeso;
						nodosAc[adyacente] = nodosAc[nodo] + 1;
						links[adyacente] = nodo;
						cola.push({ posiblepeso,adyacente });
					}
				}
			}
		}

		stack<int>q;
		q.push(t);
		poner_respuestas(q, t, links);
		q.pop();
		int ss = q.size();
		for (int i = 0; i < ss; i++) {
			auto aux = q.top(); q.pop();
			char aux2 = convertIntToChar(aux);
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
