#include <stdio.h>
#include <string>
#include <map>
using namespace std;
int main() {
	int t;
	char token;
	scanf("%d\n\n", &t);
	int aux = t;
	while (t--) {
		if (t != aux - 1)printf("\n");
		map<string, int> dict;
		int n = 0;
		while (true) {
			token = getchar();
			if (token == '\n' || token == EOF) break;
			string s;
			s.push_back(token);
			while (true) {
				token = getchar();
				if (token == '\n' || token == EOF) 
					break;
				s.push_back(token);
			}
			if (!dict.insert({ s,1 }).second) {
				dict[s]++;
			}
			n++;
		}

		for (auto it = dict.begin(); it != dict.end(); it++) {
			printf("%s %.4f\n", (*it).first.c_str(), ((float)(*it).second / n) * 100);
		}
	}
	return 0;
}