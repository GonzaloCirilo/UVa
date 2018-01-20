#include <stdio.h>
#include <string.h>
#include <vector>
using namespace std;
int main() {
	char rune[601];
	int t;
	vector<char>word = { 'M','A','R','G','I','T' };
	scanf("%d", &t);
	for (int i = 0; i<t; i++) {		
		//gets(rune);
		scanf("%600s", &rune);
		vector<int> times = vector<int>(26, 0);
		int size = strlen(rune);
		for (int j = 0; j < size; j++) {
			times[(int)rune[j]-65] += 1;
		}
		times[(int)word[1]-65] /= 3;
		times[(int)word[2]-65] /= 2;
		int min = 999999;
		for (int j = 0; j < word.size(); j++) {
			if (times[(int)word[j]-65]<min) {
				min = times[(int)word[j]-65];
			}
		}
		if (min == 999999)min = 0;
		printf("%d\n", min);
	}
	return 0;
}