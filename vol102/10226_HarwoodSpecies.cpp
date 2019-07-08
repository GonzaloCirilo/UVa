#include <stdio.h>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main() {
	int t;
	char token;
	scanf("%d\n\n", &t);
	int aux = t;
	while (t--) {
		if (t != aux - 1)printf("\n");
		unordered_map<string, int> dict;
		vector<string> ss = vector<string>();
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
			}else{
				ss.push_back(s);
			}
			n++;
		}
		sort(ss.begin(),ss.end());
		for (auto it = ss.begin(); it != ss.end(); it++) {
			printf("%s %.4f\n", (*it).c_str(), ((float)dict[*it] / n) * 100);
		}
	}
	return 0;
}