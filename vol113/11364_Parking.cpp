#include <stdio.h>
#include <algorithm>
using namespace std;
int main(){
	int t, n, vec[102];
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		for(int i = 0; i < n; i++)
			scanf("%d", &vec[i]);
		sort(vec,vec+n);
		printf("%d\n", 2*(vec[n-1]-vec[0]));
		t--;
	}
	return 0;
}