#include <stdio.h>
int main(){
	int n, x, ans, cont = 1;
	while(scanf("%d", &n) && n){
		ans = 0;
		while(n){
			scanf("%d", &x);
			if(x)
				ans++;
			else
				ans--;
			n--;
		}
		printf("Case %d: %d\n", cont, ans);
		cont++;
	}
	return 0;
}