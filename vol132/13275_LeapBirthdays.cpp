#include <stdio.h>
using namespace std;
int main(){
	int d, m, y, qy, t, ans;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d %d %d", &d, &m, &y, &qy);
		if( d == 29 && m == 2){
			 ans = qy/4 - qy/100 + qy/400 - y/4 + y/100 - y /400;
		}else{
			ans = qy - y;
		}
		printf("Case %d: %d\n", i+1, ans);
	}
	return 0;
}