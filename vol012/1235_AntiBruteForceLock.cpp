#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
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
	if (!isSameSet(a, b)) {
		pset[findset(a)] = findset(b);
	}
}
int calcRolls(int a, int b) {
	int ans = 0;
	while (a > 0 || b > 0) {
		int c1 = a % 10, c2 = b % 10;
		ans += min(abs(c1 - c2), 10 - abs(c1 - c2));
		a /= 10, b /= 10;
	}
	return ans;
}
int main() {
	int ta, n, key;
	scanf("%d", &ta);
	for (int t = 0; t < ta; t++) {
		scanf("%d", &n);
		vector<int> keys = vector<int>(1, 0);
		priority_queue<iii, vector<iii>, greater<iii>>pq, pqstart;
		int c = 1;
		for (int i = 0; i < n; i++) {
			scanf("%d", &key);
			pqstart.push({ calcRolls(keys[0], key),{ 0,c } });
			for (int j = 1; j < keys.size(); j++) {
				pq.push({ calcRolls(keys[j], key),{j,c} });
			}
			keys.push_back(key);
			c++;
		}
		init(c);
		int mst = 0, cont = 0;
		while (!pq.empty() && cont < n) {
			if (!isSameSet(pq.top().second.first, pq.top().second.second)) {
				unionset(pq.top().second.first, pq.top().second.second);
				mst += pq.top().first;
			}
			pq.pop();
		}
		printf("%d\n", mst + pqstart.top().first);
	}
	return 0;
}