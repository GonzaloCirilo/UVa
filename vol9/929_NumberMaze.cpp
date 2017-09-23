#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
priority_queue<iii, vector<iii>, greater<iii>>pq;
vector<vector<int>> distancias;
vector<vector<int>> matrix;
int n, m;
vector<ii>movimientos = { {0,1},{0,-1},{1,0},{-1,0} };
bool valido(int x, int y) {
	return (x >= 0 && x < m) && (y >= 0 && y < n);
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		scanf("%d\n%d", &n, &m);
		distancias = vector<vector<int>>(n, vector<int>(m, -1));
		matrix = vector<vector<int>>(n, vector<int>(m));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				scanf("%d", &matrix[i][j]);
			}
		}

		distancias[0][0] = matrix[0][0];
		pq.push({ matrix[0][0],{ 0,0 } });
		while (!pq.empty()) {
			ii nodo = pq.top().second;
			int peso = pq.top().first;
			pq.pop();
			ii adyacente;
			if (distancias[nodo.first][nodo.second] >= peso) {
				for (int i = 0; i < movimientos.size(); i++) {
					adyacente = { nodo.first + movimientos[i].second,nodo.second + movimientos[i].first };
					if (valido(adyacente.second, adyacente.first)) {
						int pesoady = matrix[adyacente.first][adyacente.second];
						int posiblepeso = peso + pesoady;
						if (distancias[adyacente.first][adyacente.second] == -1 || distancias[adyacente.first][adyacente.second] > posiblepeso) {
							distancias[adyacente.first][adyacente.second] = posiblepeso;
							pq.push({ posiblepeso,adyacente });
						}
					}
				}
			}
		}


		printf("%d\n", distancias[n - 1][m - 1]);
	}
	return 0;
}


