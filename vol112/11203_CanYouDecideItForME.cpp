#include <stdio.h>
#include <string>
#include <iostream>
#include <regex>
using namespace std;
bool isAxiom(string s) {
	int aux[3] = { 0,0,0 }, cont = 0;
	for (auto it = s.begin(); it != s.end(); ++it) {
		if (*it == '?')
			aux[cont]++;
		else
			cont++;
	}
	return aux[0] + aux[1] == aux[2];
}
int main() {
	string s; int n;
	scanf("%d\n", &n);
	while (n) {
		cin >> s;
		if (regex_match(s, regex("\\?+[M]\\?+[E]\\?+")) && isAxiom(s))
			printf("theorem\n");
		else
			printf("no-theorem\n");
		n--;
	}

	return 0;
}