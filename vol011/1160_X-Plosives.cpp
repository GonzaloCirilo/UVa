#include <stdio.h>
#include <vector>
using namespace std;
vector<int>pset;
int ans;
void init(){
	ans = 0;
	pset = vector<int>(100009,-1);
}
int findset(int node){
	if(-1 == pset[node])
		return node;
	return pset[node] = findset(pset[node]);
}

bool isSameSet(int a, int b){
	return findset(a) == findset(b);
}

void unionset(int a, int b){
	if(!isSameSet(a,b)){
		pset[findset(a)] = findset(b);
	}else
		ans++;
}

int main(){
	int n1,n2;
	init();
	while(scanf("%d", &n1) != EOF){
		if(n1 == -1){
			printf("%d\n", ans);
			init();
			continue;
		}
		scanf("%d", &n2);
		unionset(n1,n2);
	}
	return 0;
}