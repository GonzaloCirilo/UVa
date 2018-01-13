// 558_Wormholes.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int>ii;
typedef vector<ii> vii;
typedef vector<vii>Gi;
Gi grafo;
vector<int>distancias;
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		int n, m;
		scanf("%d %d", &n, &m);
		grafo = vector<vii>(n);
		distancias = vector<int>(n,-1);
		for (int j = 0; j < m; j++) {
			int u, v, w;
			scanf("%d %d %d", &u, &v, &w);
			grafo[u].push_back({ v,w });
		}
		queue<ii>cola;
		cola.push({ 0,0 });
		distancias[0] = 0;
		int cont = 0;
		while (!cola.empty() && cont <= m) {
			int nodo = cola.front().first;
			int peso = cola.front().second;
			cola.pop();
			if (peso <= distancias[nodo]) {
				for (int i = 0; i < grafo[nodo].size(); i++) {
					int adyacente = grafo[nodo][i].first;
					int pesoad = grafo[nodo][i].second;
					int posiblepeso = peso + pesoad;
					if (distancias[adyacente] == -1 || posiblepeso < distancias[adyacente]) {
						distancias[adyacente] = posiblepeso;
						cola.push({ adyacente,posiblepeso });
						cont++;
					}
					
				}
			}
		}
		if (cola.empty())printf("not possible\n"); else printf("possible\n");
	}
	return 0;
}