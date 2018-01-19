#include <stdio.h>
#include <vector>
using namespace std;
vector<long long> vfib;
vector<long long> vsum;
long long n1, n2, ant;
void Fibonacci() {
	for (long long i = 2; i < 300; i++) {
		vfib[i] =  (vfib[(i - 1)] + vfib[(i - 2)])%100;
		vsum[i] = vsum[(i - 1)] + vfib[i];
	}
}
long long getNum(long long n) {
	return n/300*vsum[299]+vsum[n%300];
}
int main()
{
	int cases;
	vfib = vector<long long>(300, -1);
	vsum = vector<long long>(300, -1);
	vfib[0] = 0; vfib[1] = 1; vsum[0] = 0; vsum[1] = 1;
	Fibonacci();
	scanf("%d", &cases);
	for (int c = 0; c < cases; c++) {
		scanf("%lld %lld", &n2, &n1);
		printf("%lld\n", getNum(n1) - getNum(n2-1));
	}
    return 0;
}
