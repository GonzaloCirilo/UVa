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
	vector<int> primes, marked = vector<int>(100000001, 0);

	int p = 2;
    marked[0] = 1;
    marked[1] = 1;

	while (p * p < 100000000) {
		if (!marked[p]) {
			for (int i = p * p; i <= 100000000; i += p) {
				marked[i] = 1;
			}
		}
		p++;
	}

	int n;

	while (fastScan(n)) {
        p = n /2 - 1;
        int a = 0, b =0;
        if(n % 2 != 0 && n > 1){
            if(!marked[n - 2])
                printf("%d is the sum of 2 and %d.\n", n, n - 2);
            else
                printf("%d is not the sum of two primes!\n", n);
        }else{
            while(p >= 0){
                if(!marked[p] && !marked[n - p] && p != n - p){
                    a = p; b = n - p;
                    break;
                }
                p--;
            }
            if(!a && !b)
                printf("%d is not the sum of two primes!\n", n);
            else
                printf("%d is the sum of %d and %d.\n", n, a, b);
        }
	}

	return 0;
}