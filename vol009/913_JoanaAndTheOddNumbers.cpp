#include <stdio.h>
#include <stdint.h>
#include <math.h>
int main(){
	int64_t n;
	while(scanf("%lld", &n) != EOF){
		printf("%lld\n", (int64_t)(((n/2) + 1)*((n/2) + 1)*2 - 3) * 3);
	}
	return 0;
}