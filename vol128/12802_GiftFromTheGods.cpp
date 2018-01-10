#include <stdio.h>
#include <vector>
using namespace std;
int pal = 0;
vector<bool> prime;
void InvertNum(int n) {
	int cant;
	if (n > 0) {
		cant = n % 10;
		if (pal == 0)
			pal = cant;
		else
			pal = pal*10 + (cant);
		if (n == 0)
			return;
		else
			InvertNum(n / 10);
	}
}
void Sieve(int n)
{
	prime = vector<bool>(n + 1, true);
	for (int p = 2; p*p <= n; p++)	{
		if (prime[p] == true)		{
			for (int i = p * 2; i <= n; i += p)
				prime[i] = false;
		}
	}
}
int main(){
	int n;
	Sieve(1000000);
	while (scanf("%d", &n) == 1) {
		pal = 0;
		printf("%ld\n", 2 * n);
		InvertNum(n);
		if (n == pal && prime[n])
			break;
	}
	return 0;
}
