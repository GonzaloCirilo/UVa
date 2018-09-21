#include <stdio.h>
using namespace std;
bool fibonacci[10001];

void calFibonacci(int prev, int now){
	if(prev + now > 1000)
		return;
	fibonacci[prev + now] = true;
	calFibonacci(now, prev + now);
}

int main(){
	int n;
	calFibonacci(0,1);
	while(scanf("%d", &n) != EOF && n){
		fibonacci[n]?printf("Roberto\n"):printf("Alicia\n");
	}
	return 0;
}