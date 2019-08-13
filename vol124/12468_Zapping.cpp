#include <stdio.h>
#include <math.h>
using namespace std;
int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) && a != -1 && b != -1){
		a++,b++;
		int ans = abs(a-b);
		ans = ans > 50 ? 100 - ans : ans;
		printf("%d\n", ans);
	}
	return 0;
}