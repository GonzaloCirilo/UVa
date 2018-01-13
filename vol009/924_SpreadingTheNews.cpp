#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int>Vi;
typedef vector<Vi>Gi;
Gi grafo;
Vi distancia;
int e,m,u,c, vinicio;
Vi dia;
Vi cantpersonas;
void BFS(int nodo) {
	queue<int> cola;
	cola.push(nodo);
	distancia[nodo] = 0;
	cantpersonas[0] = 0;

	while (!cola.empty()) {
		int actual = cola.front();cola.pop();
		for (int i = 0;i < grafo[actual].size();i++) {
			int adyacente = grafo[actual][i];

			if (distancia[adyacente] < 0) {
				
				distancia[adyacente] = distancia[actual] + 1;
				int dia = distancia[adyacente];
				cantpersonas[dia] += 1;
				cola.push(adyacente);		
			}
		}
	}
}
int main()
{
	scanf("%d", &e);
	grafo = Gi(e);
	
	for (int i = 0;i < e;i++) {
		scanf("%d ", &m);
		for (int j = 0;j < m;j++) {
			scanf("%d ", &u);
			grafo[i].push_back(u);
		}
		
	}

	scanf("%d", &c);
	for (int j = 0;j < c;j++) {
		scanf("%d", &vinicio);
		distancia = Vi(e, -1);
		cantpersonas = Vi(e, 0);
		BFS(vinicio);

		int menorDia = 0;
		int boomEmp = cantpersonas[0];
		for (int i = 1;i < e;i++) {
			if (boomEmp < cantpersonas[i]) {
				menorDia = i;
				boomEmp = cantpersonas[i];
			}
		}
		if (menorDia == 0)
			printf("0\n");
		else {
			printf("%d %d\n", boomEmp, menorDia);
		}
	}
    return 0;
}
