#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int, pair<int, int>>iii;
typedef vector<int>vi;
vi pset;
void init(int n) {
	pset = vector<int>(n, -1);
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
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
int main()
{
	int s, c;
	while (scanf("%d %d", &s, &c) != EOF && s )
	{
		init(s);
		map<string, int>dictionary;
		for (int u = 0; u < s; u++) {
			char aux[256];
			scanf("%s", &aux);
			dictionary[aux] = u;
		}
		priority_queue<iii, vector<iii>, greater<iii>>pq;
		for (int u = 0; u < c; u++) {
			char s[256], t[256]; int w;
			scanf("%s %s %d", &s, &t, &w);
			string sy = s, ty = t;
			pq.push({ w,{dictionary[sy],dictionary[ty]} });

		}
		char a[256];
		scanf("%s", a);//this input doesnt matter at all since we are applying kruskal's algorithim
		int cont = 0; int mst = 0;
		while (!pq.empty() && cont < s - 1) {
			auto aux = pq.top(); pq.pop();
			if (!isSameSet(aux.second.first, aux.second.second)) {
				unionSet(aux.second.first, aux.second.second);
				mst += aux.first;
				cont++;
			}
		}
		if (cont == s - 1) {
			printf("%d\n", mst);
		}
		else {
			printf("Impossible\n");
		}
	}
	return 0;
}
