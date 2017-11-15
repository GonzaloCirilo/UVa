#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <functional>
using namespace std;
typedef pair<double, pair<int, int>> iii;
int n, r, x, y;
vector<int>pset;
vector<pair<int, int>>posiciones;
void init() {
	pset = vector<int>(n);
	for (int i = 0; i < pset.size(); i++) {
		pset[i] = i;
	}
}

int findset(int nodo) {
	if (nodo == pset[nodo])
		return pset[nodo];
	return pset[nodo] = findset(pset[nodo]);
}

bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}

void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
double calcularDist(int u, int v) {
	double dist = sqrt(pow(posiciones[v].first-posiciones[u].first,2) + pow(posiciones[v].second - posiciones[u].second,2));
	return dist;
}
priority_queue<iii, vector<iii>, greater<iii>>pq;
int main()
{
	int t;
	scanf("%d", &t);
	for (int casos = 0; casos<t; casos++) {
		scanf("%d %d", &n, &r);
		init();
		int cont = 0;
		while (!pq.empty())pq.pop();
		posiciones.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			posiciones.push_back({ x,y });
		}
		int a = 0;
		for (int u = 0; u < n; u++) {
			for (int v = 1+u; v < n; v++) {
				a++;
				pq.push({ calcularDist(u,v),{ u,v } });
			}
		}
		double mst1 = 0, mst2 = 0;int numStates = 1;
		while (!pq.empty() && cont < n - 1) {
			iii tri = pq.top(); pq.pop();
			if (!isSameSet(tri.second.first, tri.second.second)) {
				cont++;
				if (tri.first <= (double)r) {
					mst1 += tri.first;
				}
				else {
					mst2 += tri.first;
					numStates += 1;
				}
				unionset(tri.second.first, tri.second.second);
			}
		}
		printf("Case #%d: %d %d %d\n", casos + 1, numStates, (int)round(mst1), (int)round(mst2));
	}
	return 0;
}
