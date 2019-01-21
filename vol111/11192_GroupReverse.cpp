#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
	int g;
	char s[102];
	while (scanf("%d", &g) && g) {
		scanf("%s", &s);
		int l = strlen(s);
		g = l / g;
		char ans[102]; int aux = g;
		for (int i = 0; i < l; i++) {
			int k = (i / g)*g;
			ans[aux + k] = s[i];
			aux--;
			aux = aux <= 0 ? g : aux;
		}
		for (int i = 1; i <= l; i++) {
			printf("%c", ans[i]);
		}
		printf("\n");
	}
	return 0;
}