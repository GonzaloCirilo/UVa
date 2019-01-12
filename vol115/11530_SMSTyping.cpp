#include <stdio.h>
#include <string.h>
#include <iostream>
int main() {
	int n; 
	scanf("%d", &n);
	getchar();
	for (int i = 0; i < n; i++) {
		char token[101];
		fgets(token, 101, stdin);
		int l = strlen(token), ans = 0;
		for (int j = 0; j < l; j++) {
			if (token[j] == '\n')break;
			int prev = ans;
			if (token[j] == ' ')
				ans++;
			else {
				if (token[j] == 's' || token[j] == 'z')
					ans += 4;
				else
					ans += ((token[j] - 'a' - (1 * (token[j] - 't' >= 0))) % 3) + 1;
			}
		}
		printf("Case #%d: %d\n", i + 1, ans);
	}
	return 0;
}