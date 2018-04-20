#include <stdio.h>
#include <math.h>
int main(){
	int n;
	while(scanf("%d", &n) && n){
		printf("%d\n", (int)((n - pow(2,(int)ceil(log2(n) - 1)))* 2));
	}
	return 0;
}