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
	char s[31];
	while (scanf("%30s", &s) != EOF) {
		int l = strlen(s);
		char prev = ' '; long long ans = 0;
		for (int i = 0; i < l; i++) {
			if (m[prev] != m[s[i]] && m[s[i]]) {
				printf("%d", m[s[i]]);
			}
			prev = s[i];
		}
		printf("\n");
	}
	return 0;
}
