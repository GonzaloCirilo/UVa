#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

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

int main() {
	vector<int> primes, marked = vector<int>(1000001, 0);

	int p = 2;

	while (p * p < 1000000) {
		if (!marked[p]) {
			for (int i = p * p; i <= 1000000; i += p) {
				marked[i] = 1;
			}
		}
		p++;
	}

	int n;

	while (scanf("%d", &n) != EOF && n) {
        printf("%d:\n", n);
        p = 2;
        while(p < n /2 + 1){
            if(!marked[p] && !marked[n - p]){
                printf("%d+%d\n", p, n - p);
                break;
            }
            p++;
        }
        if(!marked[p] && !marked[n - p])
            continue;
        else
            printf("NO WAY!\n");
		
	}

	return 0;
}