#include <stdio.h>
#include <math.h>
int main(){
	int tc, d, u, v;
	scanf("%d", &tc);
	for(int i = 0; i < tc; i++){
		scanf("%d %d %d", &d, &v, &u);
		printf("Case %d: ", i + 1);
		if(u <= v || u == 0 || v == 0)
			printf("can't determine");
		else{
			double ans = abs((double)d/u - (double)d/sqrt(u*u - v*v));
			printf("%.3f", ans);
		}
		printf("\n");
	}
	return 0;
}