#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Gi;
typedef vector<bool>Vb;
Vb visitados;
int cases, ndominoes, lines, l, u, v;
Gi grafo;
int resp = 0;
void DFS(int nodo)
{
	visitados[nodo] = true; resp++;
	for (int i = 0; i < grafo[nodo].size(); i++)
	{
		int adyacente = grafo[nodo][i];
		if (visitados[adyacente] == false)
			DFS(adyacente);
	}
}
int main()
{
	scanf("%d", &cases);
	for (int i = 0; i < cases; i++) {
		scanf("%d %d %d", &ndominoes, &lines, &l);
		resp = 0;
		grafo = Gi(ndominoes);
		for (int j = 0; j < lines; j++) {
			scanf("%d %d", &u, &v);
			u--; v--;
			grafo[u].push_back(v);
		}
		visitados = Vb(ndominoes, false);
		for (int j = 0; j < l; j++) {
			int ls;
			scanf("%d", &ls); ls--;
			if(visitados[ls]==false)DFS(ls);
		}
		
		printf("%d\n", resp);
	}
	return 0;
}
