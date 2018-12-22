#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int,pair<int,int>>iii;
vector<int> pset, nele, degree;
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
int getNele(int n){
	if(pset[n] == -1)
		return nele[n];
	return getNele(pset[n]);
}
bool isSameSet(int a, int b){
	return findSet(a) == findSet(b);
}
void unionSet(int a, int b){
	if(!isSameSet(a,b)){
		int sa = findSet(a), sb = findSet(b);
		nele[sb] += nele[sa];
		nele[sa] = 0;
		pset[sa] = sb;
	}
}
int main(){
	int v, e, t, a, b, ans, cases = 1;
	while(scanf("%d %d %d", &v, &e, &t) && v && t){
		init(v);
		ans = 0;
		for(int i = 0; i < e; i++){
			scanf("%d %d", &a, &b);
			unionSet(a-1,b-1);
			degree[a-1]++;
			degree[b-1]++;
			ans += t;
		}
		for(int i = 0; i < v; i++){
			if(getNele(i) == 1) continue; 
			for(int j = i + 1; j < v; j++){
				if(getNele(j) > 1 && !isSameSet(i,j) && (degree[i] %2 !=0 && degree[j]%2!=0)){
					ans += t;
					unionSet(i,j);
					degree[i]++;
					degree[j]++;
				}
			}
		}
		for(int i = 0; i < v; i++){
			if(getNele(i) == 1) continue; 
			for(int j = i + 1; j < v; j++){
				if(getNele(j) > 1 && !isSameSet(i,j) && (degree[i] %2 !=0 || degree[j]%2!=0)){
					ans += t;
					unionSet(i,j);
					degree[i]++;
					degree[j]++;
				}
			}
		}
		int nOdd = 0;
		for(int i = 0; i < v; i++){
			if(degree[i] % 2 != 0){
				nOdd++;
			}
		}
		if(nOdd != 0)
			nOdd = t * ((nOdd - 2)/2); 
		printf("Case %d: %d\n", cases, ans + nOdd);
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