#include <stdio.h>
int main(){
	int a, b, c, d, ans;
	while(scanf("%d %d %d %d", &a, &b, &c, &d) && (a || b || c || d)){
		ans = 1080 + ((a-b)+40*(a-b < 0))*9 + ((c-b)+40*(c-b < 0))*9 + ((c-d)+40*(c-d < 0))*9;
		printf("%d\n", ans);
	}
	return 0;
}