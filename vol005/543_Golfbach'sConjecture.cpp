#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

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

	marked.clear();
	int n;

	while (scanf("%d", &n) != EOF && n) {
        p = 2;
        while(p < n /2 + 1){
            if(!marked[p] && !marked[n - p]){
                printf("%d = %d + %d\n", n, p, n - p);
                break;
            }
            p++;
        }
        if(!marked[p] && !marked[n - p])
            continue;
        else
            printf("Goldbach's conjecture is wrong.");
		
	}

	return 0;
}