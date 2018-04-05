#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
vector<int>pset;
typedef pair<int, int>ii;
typedef pair<int, ii>iii;
typedef priority_queue<iii, vector<iii>, greater<iii>> pq_iii;
int cont, l;
void init(int n) {
	pset = vector<int>(n, -1);
}
int findset(int node) {
	if (-1 == pset[node])
		return node;
	return pset[node] = findset(pset[node]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionset(int a, int b, int c) {
	if (!isSameSet(a, b)) {
		pset[findset(a)] = findset(b);
		cont++;
		l += c;
	}
}
void read(int n, pq_iii &pq) {
	int u, v, c;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &u, &v, &c);
		u--, v--;
		pq.push({ c,{ u,v } });
	}
}
int mst(pq_iii pq, int n) {
	cont = 0; l = 0;
	while (!pq.empty() && cont != n - 1) {
		iii aux = pq.top(); pq.pop();
		unionset(aux.second.first, aux.second.second, aux.first);
	}
	return l;
}
int main() {
	int n, a1, a2, t = 0;
	while (scanf("%d", &n) != EOF) {
		if (t != 0)
			printf("\n");
		init(n);
		pq_iii pq;
		read(n - 1, pq);
		scanf("%d", &n);
		read(n, pq);
		a2 = mst(pq, pset.size());
		scanf("%d", &n);
		pq = pq_iii();
		read(n, pq);
		init(pset.size());
		a1 = mst(pq, pset.size());
		printf("%d\n%d\n", a1, a2);
		t++;
	}
	return 0;
}
