#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;
typedef pair<int, int> ii;
typedef vector<int>vii;
typedef vector<vii>G;
int main() {
	char name[11];
	string s;
	map<int, string> map;
	int n, m, u, v, w;
	G graph;
	int ca = 1;
	while (true) {
		map.clear();
		graph = G(22, vii(22, 9999999));
		for (int i = 0; i < 22; i++) {
			graph[i][i] = 0;
		}
		scanf("%d %d", &n, &m);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			scanf("%s", &name);
			s = string(name);
			map[i] = s;
		}
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &u, &v, &w);
			u--; v--;
			graph[u][v] = w;
			graph[v][u] = w;
		}
		for (int k = 0; k < n; k++) {
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (graph[i][j] > graph[i][k] + graph[k][j]/*&& k <= i && k >= j*/)
						graph[i][j] = graph[i][k] + graph[k][j];
				}
			}
		}
		int min = 9999999, index = 0;
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < n; j++) {
				sum += graph[i][j];
			}
			if (sum < min) {
				min = sum;
				index = i;
			}
		}
		printf("Case #%d : ", ca);
		cout << map[index] << endl;
		ca++;
	}
	return 0;
}
