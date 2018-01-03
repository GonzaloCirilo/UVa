#include <stdio.h>
#include <queue> 
using namespace std;

int main(){
	while(true){
		int n;
		queue<int> q;
		scanf("%d",&n);
		if(n==0)break;
		printf("Discarded cards:");
		for(int i=1;i<=n;i++){
			q.push(i);
		}
		int c=1;
		while(q.size()>1){
			c++;
			int r=q.front();q.pop();
			if(c==n){
				printf(" %d", r);
			}else{
				printf(" %d,", r);				
			}

			r=q.front();q.pop();
			q.push(r);
		}
		printf("\nRemaining card: %d\n",q.front());
		
	}
	return 0;
}