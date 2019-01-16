#include <stdio.h>
using namespace std;
int main() {
	int n, arr[13];
	char tokens[27];
	while (scanf("%d\n", &n) && n) {
		int max = 0;
		for (int j = 0; j < n; j++) {
			arr[j] = 0;
			fgets(tokens, 27, stdin);
			for (int i = 0; i < 25; i++) {
				arr[j]+= (int)(tokens[i] == 'X');
			}
			max = max < arr[j] ? arr[j] : max;
		}
		int ans = 0;
		for (int j = 0; j < n; j++) {
			ans += max - arr[j];
		}
		printf("%d\n", ans);
	}

	return 0;
}