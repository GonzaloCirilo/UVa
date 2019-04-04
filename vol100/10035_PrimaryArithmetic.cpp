#include <stdio.h>

int main(){
	int a, b;
	while(scanf("%d %d", &a, &b) && (a || b)){
		int cont = 0, ans = 0, carry = 0;
		while((a > 0 || b > 0)){
			int aux = a % 10 + b % 10+ carry;
			ans += (aux >= 10);
			carry = (aux >= 10);
			a /= 10;
			b /= 10;
		}
		if(ans){
			printf("%d carry operation", ans);
			if(ans > 1)
				printf("s");
			printf(".\n");
		}
		else
			printf("No carry operation.\n");
	}
	return 0;
}