#include <stdio.h>
#include <list>
#include <string.h>
using namespace std;
int main() {
	char token[100001];
	while (scanf("%s", &token) != EOF) {
		int l = strlen(token);
		list<char> lis; auto it = lis.end();
		for (int i = 0; i < l; i++) {
			if (token[i] != '[' && token[i] != ']') {
				lis.insert(it, token[i]);
			}
			else {
				if (token[i] == '[')
					it = lis.begin();
				else
					it = lis.end();
			}
		}
		for (auto itt= lis.begin(); itt != lis.end(); itt++) {
			printf("%c", *itt);
		}
		printf("\n");
	}
	return 0;
}