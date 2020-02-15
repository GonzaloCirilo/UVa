#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector<int> primes, marked = vector<int>(40001, 0);

	int p = 2;

	while (p * p < 40000) {
		if (!marked[p]) {
			for (int i = p * p; i <= 40000; i += p) {
				marked[i] = 1;
			}
		}
		p++;
	}

	marked.clear();
	int n;

	while (scanf("%d", &n) != EOF && n) {
        p = 2;
        int ans = 0;
        while(p < n /2 + 1){
            if(!marked[p] && !marked[n - p]){
                ans++;
            }
            p++;
        }
        printf("%d\n", ans);
	}

	return 0;
}