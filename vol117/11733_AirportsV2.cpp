#include <stdio.h>
#include <vector>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
vector<int> pset; int na, maxe;
iii arr[100001], aux[100001];
void init(int n) {
	pset = vector<int>(n, -1);
	na = n;
}
int findset(int p) {
	if (-1 == pset[p])
		return p;
	return pset[p] = findset(pset[p]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}
void unionSet(int a, int b) {
	pset[findset(a)] = findset(b);
	na--;
}
void countSort(int e,int n) {
	int count[10] = {};
	for (int i = 0; i < n; i++)
		count[(arr[i].first / e) % 10]++;
	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (int i = n - 1; i >= 0; i--) {
		aux[count[(arr[i].first / e) % 10] - 1] = arr[i];
		count[(arr[i].first / e) % 10]--;
	}
	for (int i = 0; i < n; i++)
		arr[i] = aux[i];
}
void radixSort(int n) {
	for (int exp = 1; maxe / exp > 0; exp *= 10)
		countSort(exp, n);
}
void fastscan(int &x) {
	bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}
int main() {
	int ta, n, m, a, u, v, c;
	fastscan(ta);
	for (int t = 0; t < ta; t++) {
		fastscan(n);
		fastscan(m);
		fastscan(a);
		maxe = 0;
		for (int i = 0; i < m; i++) {
			fastscan(u);
			fastscan(v);
			fastscan(c);
			u--, v--;
			maxe = maxe < c ? c : maxe;
			arr[i] = { c,{u,v} };
		}
		init(n);
		int mst = 0, cont = 0;
		radixSort(m);
		for (int i = 0; i < m && cont != n -1 && arr[i].first < a; i++) {
			iii aux = arr[i];
			if (!isSameSet(aux.second.first, aux.second.second)) {
				mst += aux.first;
				unionSet(aux.second.first, aux.second.second);
			}
		}
		printf("Case #%d: %d %d\n", t + 1, mst + (a * na), na);
	}
	return 0;
}
