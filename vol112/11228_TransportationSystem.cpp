#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <functional>
using namespace std;
typedef pair<double, pair<int, int>> iii;
int n, r, x, y;
vector<int>pset;
vector<pair<int, int>>positions;
void init() {
	pset = vector<int>(n);
}
int findset(int node) {
	if (node == pset[node])
		return pset[node];
	return pset[node] = findset(pset[node]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
double calDistance(int u, int v) {
	return sqrt(pow(positions[v].first - positions[u].first, 2) + pow(positions[v].second - positions[u].second, 2));
}
int main()
{
	int t;
	scanf("%d", &t);
	for (int cases = 0; cases<t; cases++) {
		scanf("%d %d", &n, &r);
		init();
		int cont = 0;
		priority_queue<iii, vector<iii>, greater<iii>>pq;
		positions = vector<pair<int, int>>();
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &x, &y);
			positions.push_back({ x,y });
			pset[i] = i;
		}
		for (int u = 0; u < n; u++) {
			for (int v = 1 + u; v < n; v++) {
				pq.push({ calDistance(u,v),{ u,v } });
			}
		}
		double mst1 = 0, mst2 = 0; int numStates = 1;
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
		printf("Case #%d: %d %d %d\n", cases + 1, numStates, (int)round(mst1), (int)round(mst2));
	}
	return 0;
}
