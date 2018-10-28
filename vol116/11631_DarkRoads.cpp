#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef pair<int, pair<int, int>> iii;
int m, n, x, y, z;
vector<int>pset;
void init() {
	pset = vector<int>(m, -1);
}
int findset(int nodo) {
	if (-1 == pset[nodo])
		return nodo;
	return pset[nodo] = findset(pset[nodo]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
priority_queue<iii, vector<iii>, greater<iii>>pq;
int main()
{
	while (true) {
		scanf("%d %d", &m, &n);
		if (m == 0 && n == 0)break;
		while (!pq.empty())pq.pop();
		int sumt = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d %d %d", &x, &y, &z);
			pq.push({ z,{x,y} });
			sumt += z;
		}

		int cont = 0;
		int mst = 0;
		init();
		while (!pq.empty() && cont < n - 1) {
			iii tri = pq.top();
			pq.pop();
			if (!isSameSet(tri.second.first, tri.second.second)) {
				cont++;
				mst += tri.first;
				unionset(tri.second.first, tri.second.second);
			}
		}
		printf("%d\n", (sumt - mst));
	}
	return 0;
}
