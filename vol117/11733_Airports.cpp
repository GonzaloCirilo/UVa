#include <stdio.h>
#include <vector>
#include <queue>
#include <functional>
using namespace std;
typedef pair<int,int> ii;
typedef pair<int, ii> iii;
vector<int> pset;
void init(int n){
	pset = vector<int>(n);
	for(int i = 0; i < n; i++){
		pset[i] = i;
	}
}
int findset(int p) {
	if (p == pset[p])
		return p;
	return pset[p] = findset(pset[p]);
}
bool isSameSet(int a,int b) {
	return findset(a) == findset(b);
}
void unionSet(int a, int b) {
	if (!isSameSet(a, b))
		pset[findset(a)] = findset(b);
}
int main(){
	int ta, n, m, a, u, v, c;
	scanf("%d", &ta);
	for(int t = 0; t < ta; t++){
		scanf("%d %d %d", &n, &m, &a);
		priority_queue<iii, vector<iii>, greater<iii> >pq;
		for(int i = 0; i < m; i++){
			scanf("%d %d %d", &u, &v, &c);
			u--,v--;
			pq.push({ c,{u,v} });
		}
		init(n);
		int mst = 0;
		while(!pq.empty() && pq.top().first < a){
			if(!isSameSet(pq.top().second.first,pq.top().second.second)){
				mst += pq.top().first;
				unionSet(pq.top().second.first,pq.top().second.second);
			}
			pq.pop();
		}
		int na = 0;
		for(int i = 0; i < pset.size(); i++){
			if(pset[i] == i){
				mst += a;
				na++;
			}
		}
		printf("Case #%d: %d %d\n", t+1, mst, na);
	}
	return 0;
}
