#include <stdio.h>
#include <vector>
#include <set>
using namespace std;

int main() {
	vector<int> marked = vector<int>(10000001, 0);

	int p = 2;

	while (p * p < 10000000) {
		if (!marked[p]) {
			for (int i = p * p; i <= 10000000; i += p) {
				marked[i] = 1;
			}
		}
		p++;
	}

	int n;

	while (scanf("%d", &n) != EOF && n) {
        p = 2;
        int auxN = n - 4;
        if (n < 8) {
            printf("Impossible.\n");
            continue;
        }
        while(p < auxN /2 + 1){
            if(!marked[p] && !marked[auxN - p]){
                printf("2 2 %d %d\n", p, auxN - p);
                break;
            }
            p++;
        }
        if(!marked[p] && !marked[auxN - p])
            continue;
        else {
            auxN = n - 5; p = 2;
            while(p < auxN /2 + 1){
                if(!marked[p] && !marked[auxN - p]){
                    printf("2 3 %d %d\n", p, auxN - p);
                    break;
                }
                p++;
            }
            if(!marked[p] && !marked[auxN - p])
                continue;
            else
                printf("Impossible.\n");
        }
		
	}

	return 0;
}