#include <stdio.h>
#include <vector>
using namespace std;
vector<int>starting;
vector<int>ending;
int main(){
	int n, x, y, sa=10001, ea=0;
	while(true){
		scanf("%d", &n);
		if(n==0)break;
		starting = vector<int>(10001);
		ending = vector<int>(10001);
		for(int i = 0; i < n; i++){
			scanf("%d %d", &x, &y);
			if(x-y>0){
				starting[x-y]+=1;
				if(x-y<sa)sa=x-y;
			}
			else{
				starting[0]+=1;
				if(0<sa)sa=0;
			}
			if(x+y<10001){
				ending[x+y]+=1;
				if(x+y>ea)ea=x+y;	
			}else{
				if(10000>ea)ea=10000;
			}

		}
		int ans = 0, sweep=0;
		for(int i = sa; i <= ea; i++){
			sweep+=starting[i];
			if(ans<sweep)ans=sweep;
			sweep-=ending[i];
		}
		printf("%d\n", ans);
	}
	return 0;
}