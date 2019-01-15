#include <stdio.h>
#include <queue>
using namespace std;
typedef pair<int,int> ii;
int main(){
	int t, n, m, ni;
	scanf("%d", &t);
	while(t--){
		priority_queue<ii> pq;
		queue<ii> q;
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &ni);
			q.push({ ni,i });
			pq.push({ ni,i });
		}
		bool found = false; int ans = 0;
		while(!found){
			ii auxq = q.front(), auxpq = pq.top();
			if(auxq.first == auxpq.first){
				pq.pop();
				q.pop();
				ans++;
				if(auxq.second == m)
					found = true;
			}else{
				q.pop();
				q.push(auxq);
			}
			
		}
		printf("%d\n", ans);
	}
	return 0;
}