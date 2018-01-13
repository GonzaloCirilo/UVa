#include <stdio.h>
int main(){
	int s[50], n, h, sum, t = 1;
	while(true){
		sum=0;
		scanf("%d", &n);
		if(n == 0) break;
		for(int i=0; i<n; i++){
			scanf("%d", &s[i]);
			sum += s[i];
		}
		int min = sum/n, ans=0;
		for(int i=0; i<n; i++){
			if(s[i]>min)
				ans += (s[i]-min);
		}
		printf("Set #%d\nThe minimum number of moves is %d.\n\n", t, ans);
		t++;
	}
}
