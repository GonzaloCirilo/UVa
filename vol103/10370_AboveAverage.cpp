#include <stdio.h>

int main(){
	int c, n, ni[1002];
	scanf("%d", &c);
	while(c--){
		scanf("%d", &n);
		int sum = 0;
		for(int i = 0; i < n; i++){
			scanf("%d", &ni[i]);
			sum += ni[i];
		}
		double average = (double)sum / n, ans = 0.0;
		for(int i = 0; i < n; i++){
			if(average < (double)ni[i])
				ans += 1.0f/n;
		}
		ans *= 100;
		printf("%.3f%\n",ans);
	}
	return 0;
}