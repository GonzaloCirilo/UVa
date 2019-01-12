#include <stdio.h>
#include <string>
#include <string.h>
using namespace std;
int main() {
	int t;
	char tokens[1001];
	scanf("%d\n", &t);
	while (t--) {
		fgets(tokens, 1001, stdin);
		string s = string(tokens);
		int l = strlen(tokens) - 1;
		
		if (s[l - 1] == '5')
			printf("-\n");
		else if (s[0] == '9' && s[l - 1] == '4')
			printf("*\n");
		else if(s[0] == '1' && s[1] == '9' && s[2] == '0')
			printf("?\n");
		else //if (s[0] == '4' || s[0] == '7' || s[0] == '1')
			printf("+\n");
			
	}
	return 0;
}