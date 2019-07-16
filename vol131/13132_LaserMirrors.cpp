#include <stdio.h>
int vphi[100001];
bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
void phi(int n){
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
	scanf("%d\n", &t);
	phi(100000);
	while(t){
		fastScan(n);
		printf("%d\n", vphi[n]);
		t--;
	}
	return 0;
}