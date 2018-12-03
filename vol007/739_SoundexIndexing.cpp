#include <stdio.h>
#include <vector>
#include <map>
#include <string.h>
using namespace std;
int main() {
	map<char, int> m;
	m['A'] = 0; m['E'] = 0; m['I'] = 0; m['O'] = 0; m['U'] = 0; m['H'] = 0; m['W'] = 0; m['Y'] = 0;
	m['B'] = 1; m['F'] = 1; m['P'] = 1; m['V'] = 1;
	m['C'] = 2; m['G'] = 2; m['J'] = 2; m['K'] = 2; m['Q'] = 2; m['S'] = 2; m['X'] = 2; m['Z'] = 2;
	m['D'] = 3; m['T'] = 3;
	m['L'] = 4;
	m['M'] = 5; m['N'] = 5;
	m['R'] = 6;
	char s[21];
	printf("         NAME                     SOUNDEX CODE\n");
	while (scanf("%20s", &s) != EOF) {
		int l = strlen(s);
		char prev = s[0];
		printf("         %-25s%c", s, s[0]); int cont = 0;
		for (int i = 1; i < l && cont < 3; i++) {
			if (m[prev] != m[s[i]] && m[s[i]]) {
				printf("%d", m[s[i]]);
				cont++;
			}
			prev = s[i];
		}
		for(int i = cont; i < 3; i++)
			printf("%d",0);
		printf("\n");
	}
	printf("                   END OF OUTPUT\n");
	return 0;
}
