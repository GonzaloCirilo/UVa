#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii> dii;
vector<int>pset;
vector<ii>coords;
void init(int n) {
	pset = vector<int>(n);
	for (int i = 0; i < n; i++) {
		pset[i] = i;
	}
}
int findset(int n) {
	if (n == pset[n])
		return pset[n];
	return pset[n] = findset(pset[n]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
double calDistance(int a, int b) {
	return sqrt(pow(coords[a].first - coords[b].first, 2) + pow(coords[a].second - coords[b].second, 2));
}
bool oneSet() {
	int cont = 0;
	for (int i = 0; i < pset.size(); i++) {
		if (pset[i] == i)
			cont++;
		if (cont == 2)
			return false;
	}
	return true;
}
int main() {
	int tc, n, m, x, y;
	scanf("%d", &tc);
	while (tc) {
		priority_queue<dii, vector<dii>, greater<dii>> pq;
		scanf("%d", &n);
		init(n);
		coords = vector<ii>(n);
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			coords[i] = { x,y };
		}
		scanf("%d", &m);
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				pq.push({ calDistance(i,j),{ i,j } });
			}
		}
		for (int j = 0; j < m; j++) {
			scanf("%d %d", &x, &y);
			unionset(--x, --y);
		}
		int mst = 0;
		while (!pq.empty() && !oneSet()) {
			dii aux = pq.top(); pq.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				printf("%d %d\n", aux.second.first + 1, aux.second.second + 1);
				unionset(aux.second.first, aux.second.second);
				mst++;
			}
		}
		if (mst == 0)
			printf("No new highways need\n");
		tc--;
		if (tc)
			printf("\n");
	}
}
