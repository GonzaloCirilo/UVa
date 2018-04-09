#include <stdio.h>
long long n, ans[88];
long long solve(int n){
	if(ans[n] != 0)
		return ans[n];
	return ans[n] = solve(n-1) + solve(n-2);
}
int main(){
	ans[1] = 1; ans[2] = 1;
	for(int i = 3; i < 88; i++)
		ans[i] = 0;
	while(scanf("%lld", &n) && n){
		printf("%lld\n", solve(n));
	}
	return 0;
}