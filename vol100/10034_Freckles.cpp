#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
#include <math.h>
using namespace std;
typedef pair<int, int>ii;
typedef pair<double, ii> dii;
vector<int> pset;
double  euclidean(double x1, double y1, double x2, double y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
void init(int n) {
	pset = vector<int>(n, -1);
}
int findset(int n) {
	if (pset[n] == -1)
		return n;
	return pset[n] = findset(pset[n]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
bool unionSet(int a, int b) {
	if (!isSameSet(a, b)) {
		pset[findset(a)] = findset(b);
		return true;
	}
	return false;
}
int main() {
	int t, n;
	double x, y;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		init(n);
		if (i)
			printf("\n");
		priority_queue<dii,vector<dii>,greater<dii>>pq;
		vector<double> xs, ys;
		for (int u = 0; u < n; u++) {
			scanf("%lf %lf", &x, &y);
			xs.push_back(x);
			ys.push_back(y);
			for (int v = u - 1; v >= 0; v--) {
				pq.push({ euclidean(x,y,xs[v],ys[v]),{u,v} });
			}
		}
		int cont = 0; double ans = 0.0;
		while (!pq.empty() && cont < n - 1) {
			auto p = pq.top(); pq.pop();
			int u = p.second.first, v = p.second.second;
			if (unionSet(u, v)) {
				ans += p.first;
			}
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}