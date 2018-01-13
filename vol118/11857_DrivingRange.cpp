#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
vector<int> pset;
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
void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
int main() {
	int n, m, u, v, w;
	while (true) {
		scanf("%d %d", &n, &m);
		priority_queue<iii, vector<iii>, greater<iii> >pq;
		priority_queue<int, vector<int>, less<int> > ranges;
		if (n == 0 && m == 0)
			break;
		init(n);
		for (int mi = 0; mi < m; mi++) {
			scanf("%d %d %d", &u, &v, &w);
			pq.push({ w,{ u,v } });
		}
		int cont = 0;
		while (!pq.empty() && cont != n - 1) {
			iii aux = pq.top(); pq.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				unionset(aux.second.first, aux.second.second);
				ranges.push(aux.first);
				cont++;
			}
		}
		if (cont == n - 1 && m >= n - 1)
			printf("%d\n", ranges.top());
		else
			printf("IMPOSSIBLE\n");
	}
	return 0;
}
