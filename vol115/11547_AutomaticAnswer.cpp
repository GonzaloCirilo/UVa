#include <stdio.h>
#include <math.h>
int main(){
	int t, n; 
	double ans;
	scanf("%d", &t);
	while(t){
		scanf("%d", &n);
		ans = (((n * 567.0/9) + 7492.0)*235.0/47)-498;
		ans /= 10;
		printf("%d\n", (int)abs((int)ans % 10));
		t--;
	}
	return 0;
}