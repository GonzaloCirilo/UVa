#include <stdio.h>
int main() {
	char a = 'a';
	while ((a = getchar()) != EOF) {
		if (a != '\n') {
			a = (char)((int)a - 7);
		}
		printf("%c", a);
	}
}