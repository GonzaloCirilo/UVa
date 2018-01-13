#include <stdio.h>
#include <math.h>
#include <vector>
#include <string.h>
#include <map>
using namespace std;
int chartoint(char d) {
	return (int)d - 48;
}
int main() {
	int t;
	char formula[81];
	map<char, double>molarm;
	molarm['C'] = 12.010; molarm['H'] = 1.008; molarm['O'] = 16.000; molarm['N'] = 14.010;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%80s", &formula);
		int l = strlen(formula);
		double last = 0, ans = 0.0;
		int number = 0, digitcount = 0;
		for (int j = l-1; j >= 0; j--) {
			if (molarm.find(formula[j]) != molarm.end()) {
				number==0?ans += molarm[formula[j]]:ans += number*molarm[formula[j]];
				number = 0;
				digitcount = 0;
			}
			else {
				number += chartoint(formula[j])*pow(10,digitcount);
				digitcount++;
			}
		}
		printf("%.3f\n", ans);
	}
	return 0;
}
