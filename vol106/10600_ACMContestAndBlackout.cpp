#include <stdio.h>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
typedef	pair<int, int>ii;
typedef pair<int, ii>iii;
vector<int>pset;
int n;
void init() {
	pset = vector<int>(n, -1);
}
int findset(int p) {
	if (-1 == pset[p]) {
		return p;
	}
	return pset[p]=findset(pset[p]);
}
bool isSameSet(int a, int b) {
	return findset(a) == findset(b);
}

void unionset(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
int main()
{
	int cases;
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		int m;
		scanf("%d %d", &n, &m);
		init();
		priority_queue<iii, vector<iii>, greater<iii>>p;
		for (int i = 0; i < m; i++) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			p.push({ c,{a-1,b-1} });
		}
		int cont = 0;
		int mst = 0;
		vector<iii> last;
		auto copyP = p;
		while (!p.empty() && cont < n - 1) {
			auto aux = p.top(); p.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				cont++;
				mst += aux.first;
				unionset(aux.second.first, aux.second.second);
				last.push_back(aux);
			}
		}
		printf("%d ", mst);
		int minMST = 100000;
		for (int j = 0; j < last.size(); j++) {
			auto it = copyP; int c = 0;
			int mst2 = 0;
			init();
			while (!it.empty() && c < n - 1) {
				auto aux = it.top(); it.pop();
				if (!isSameSet(aux.second.first, aux.second.second) && aux.second != last[j].second) {
					c++;
					mst2 += aux.first;
					unionset(aux.second.first, aux.second.second);
				}
			}
			if (mst2 < minMST && c==n-1) {
				minMST = mst2;
			}
		}
		printf("%d\n", minMST);
	}

    return 0;
}
