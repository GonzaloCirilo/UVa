#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair <int, ii>iii;
vector<int>pset;
int ans = 0;
void init(int n) {
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
void unionset(int a, int b, int c) {
	if (!isSameSet(a, b)) {
		pset[findset(a)] = findset(b);
		ans -= c;
	}
}
int main() {
	int ca, n, m, a, b, c;
	scanf("%d", &ca);
	priority_queue<iii, vector<iii>, less<iii>>pq;
	for (int i = 0; i < ca; i++) {
		scanf("%d %d", &n, &m);
		init(n); ans = 0;
		for (int j = 0; j < m; j++) {
			scanf("%d %d %d", &a, &b, &c);
			a--; b--; ans += c;
			pq.push({ c,{ a,b } });
		}
		while (!pq.empty()) {
			iii aux = pq.top(); pq.pop();
			unionset(aux.second.first, aux.second.second, aux.first);
		}
		printf("%d", ans);
		if (i != c - 1)printf("\n");
	}
	scanf("%d", &c);
	return 0;
}