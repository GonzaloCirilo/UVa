#include <stdio.h>
#include <vector>
using namespace std;
vector<int> pset, nele, degree;
int comp;
void init(int n){
	pset = vector<int>(n, -1);
	nele = vector<int>(n, 1);
	degree = vector<int>(n, 0);
}
int findSet(int n){
	if(pset[n] == -1)
		return n;
	return pset[n] = findSet(pset[n]);
}
bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}
void unionSet(int a, int b){
	if(!isSameSet(a,b)){
		int sa = findSet(a), sb = findSet(b);
       	nele[sa] += nele[sb];
       	pset[sb] = sa;
		comp--;
	}
}
int main(){
	int v, e, t, a, b, ans, cases = 1;
	while(scanf("%d %d %d", &v, &e, &t) && v && t){
		init(v);
		comp = v;
		for(int i = 0; i < e; i++){
			scanf("%d %d", &a, &b);
			unionSet(a-1,b-1);
			degree[a-1]++;
			degree[b-1]++;
		}
		int odd[1003] = {};
		for(int i = 0; i < v; i++){
			if(nele[i] == 1 && findSet(i) == i)
				comp--; 
			if(degree[i] % 2){
				odd[findSet(i)]++;
			}
		}
		comp = comp > 0 ? comp - 1:0;
		ans = (e + comp) * t;
		for(int i = 0; i < v; i++){
			if(odd[i] > 3){
				ans += ((odd[i] - 2)/2) * t;
			}
		} 
		printf("Case %d: %d\n", cases, ans);
		cases++;
	}
	return 0;
}
/*
10 8 4
1 2
1 5
2 5
3 5
4 10
6 4
6 10
7 10
0 0 0
*/