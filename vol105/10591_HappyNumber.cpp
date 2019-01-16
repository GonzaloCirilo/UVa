#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
set<int> ns;
bool recursive(long long n) {
	if (n == 1)
		return 1;

	if (!ns.insert(n).second)
		return 0;
	
	int aux = n, newN = 0;
	while (aux) {
		int s = aux % 10; aux /= 10;
		s *= s;
		newN += s;
	}
	return recursive(newN);
}
int main() {
	long long n; int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		ns.clear();
		scanf("%lld", &n);
		printf("Case #%d: %lld is a", i + 1, n);
		if (recursive(n))
			printf(" Happy number.\n");
		else
			printf("n Unhappy number.\n");
	}
	return 0;
}