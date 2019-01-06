#include <stdio.h>
int main(){
	long long t, a, b;
	scanf("%d", &t);
	while(t){
		scanf("%lld %lld", &a, &b);
		if(a<b)
			printf("<\n");
		else{
			if(a>b)
				printf(">\n");
			else
				printf("=\n");
		}
		t--;
	}

	return 0;
}