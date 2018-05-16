#include <stdio.h>
int vphi[100001];
int phi(int n){
	for (int i=1; i<=n; i++)
        vphi[i] = i; 
 
    for (int p=2; p<=n; p++){
        if (vphi[p] == p){
            vphi[p] = p-1;
            for (int i = 2*p; i <= n; i += p){
               vphi[i] = (vphi[i]/p) * (p-1);
            }
        }
    }
}

int main(){
	int t, n;
	scanf("%d", &t);
	phi(100000);
	while(t){
		scanf("%d", &n);
		printf("%d\n", vphi[n]);
		t--;
	}
	return 0;
}