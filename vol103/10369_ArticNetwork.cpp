#include <stdio.h>
#include <queue>
#include <vector>
#include <math.h>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii>dii;
typedef vector<ii> vii;
vector<int> pset;
void init(int n) {
	pset = vector<int>(n, -1);
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
double distance(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}
int main() {
	int t, p, s, x, y;
	vii outpost;
	scanf("%d", &t);
	for (int ta = 0; ta < t; ta++) {
		priority_queue<dii, vector<dii>, greater<dii> >pq;
		scanf("%d %d", &s, &p);
		outpost.clear();
		init(p);
		for (int i = 0; i < p; i++) {
			scanf("%d %d", &x, &y);
			for (int j = 0; j < outpost.size(); j++) {
				pq.push({ distance(outpost[j].first, outpost[j].second, x, y),{j,i} });
			}
			outpost.push_back({ x,y });
		}
		double ans = 0.0; int edges = 0;
		vector<double>e;
		while(!pq.empty() && edges != p - 1) {
			dii aux = pq.top(); pq.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				unionset(aux.second.first, aux.second.second);
				edges++;
				e.push_back(aux.first);
			}
		}
		int in = p - 1 - s;
		if (in < 0)in = 0;
		if (in == p - 1) in = p - 2;
		ans = e[in];
		printf("%.2f\n", ans);
	}
	return 0;
}
