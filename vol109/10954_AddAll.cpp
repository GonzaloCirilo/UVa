#include <stdio.h>
#include <queue>
#include <functional>

using namespace std;

void fastScan(int &x){
    bool neg = false;
	register int c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}

int main(){
	int n, arr[5002];
	priority_queue<int, vector<int>, greater<int>> pq;
	while(true){
		fastScan(n);
		if(!n)break;
		for(int i = 0; i < n; i++){
			fastScan(arr[i]);
			pq.push(arr[i]);
		}
		getchar();
		if(n==1)
			pq.pop();
		int ans = 0;
		while(!pq.empty() && n != 1){
			int aux = pq.top();
			pq.pop();
			aux += pq.top();
			pq.pop();
			ans += aux;
			if(!pq.empty())
				pq.push(aux);
		}
		printf("%d\n", ans);
	}
	return 0;
}