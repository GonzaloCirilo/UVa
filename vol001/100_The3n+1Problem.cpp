
#include <stdio.h>
#include <map>
#include <queue>
using namespace std;
vector<int> a;
int evaluate(int n) {
	if (n % 2 == 0)
		return n / 2;
	else
		return 3 * n + 1;
}
int cycles(int i) {
	if (i < 1000001) {
		if (a[i] != -1)
			return a[i];
		return a[i] = 1 + cycles(evaluate(i)) ;
	}
	else
		return 1 + cycles(evaluate(i));
}
int main() {
	int i, j;
	a = vector<int>(1000001, -1);
	a[1] = 1;
	while (scanf("%d %d", &i, &j) != EOF) {
		printf("%d %d ", i, j);
		if (i > j) {
			int aux = i;
			i = j;
			j = aux;
		}
		int max = 0;
		for (; i <= j; i++) {
			int c = cycles(i);
			if (max < c)
				max = c;
		}
		printf("%d\n", max);
	}
	return 0;
}