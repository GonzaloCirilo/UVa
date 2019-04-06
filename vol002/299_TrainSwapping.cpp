#include <stdio.h>

int main(){
	int t, n, l[52];
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n);
		for(int i = 0; i < n; i++){
			scanf("%d", &l[i]);
		}
		int ans = 0;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				if(l[i]>l[j]){
					int aux = l[i];
					l[i] = l[j];
					l[j] = aux;
					ans++;
				}
			}
		}
		printf("Optimal train swapping takes %d swaps.\n", ans);
	}
}