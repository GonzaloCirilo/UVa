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
	pset = vector<int>(n,-1);
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
	if (!isSameSet(a, b)){
		pset[findset(a)] = findset(b);
	}
}
int main() {
	int n, m, u, v, w;
	while(true){
		scanf("%d %d", &n, &m);
		if(n == 0 && m == 0) break;
		init(n);
		priority_queue<iii, vector<iii>, greater<iii> > pq;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &w);
			pq.push({ w,{u,v} });
		}
		int s = 0;
		while(!pq.empty()){
			if(!isSameSet(pq.top().second.first, pq.top().second.second)){
				unionset(pq.top().second.first, pq.top().second.second);
			}else{
				if(s != 0)
					printf(" ");
				s++;
				printf("%d", pq.top().first);
			}
			pq.pop();
		}
		if(s == 0)
			printf("forest");
		printf("\n");
	}
	return 0;
}
