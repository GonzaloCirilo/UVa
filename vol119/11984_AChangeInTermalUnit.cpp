#include <stdio.h>

int main(){
	int t, c, d;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		scanf("%d %d", &c, &d);
		printf("Case %d: %.2f\n", i + 1, (((c*9.0/5+32)+d)-32)*5.0/9);
	}
	return 0;
}