#include <stdio.h>
#include <map>
#include <sstream>
using namespace std;
int main() {
	int n, pos[1001], t;
	char tokens[10001];
	string line;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		getchar();
		map<int, string>d;
		if (i)
			printf("\n");
		getchar();
		fgets(tokens, 10001, stdin);
		line = string(tokens);
		stringstream ss(line);
		int cont = 0;
		while (ss >> pos[cont++]);
		for (int j = 0; j < cont - 1; j++) {
			scanf("%s", tokens);
			d.insert({ pos[j],string(tokens) });
		}
		for (auto it = d.begin(); it != d.end(); it++) {
			printf("%s\n", (*it).second.c_str());
		}

	}
	return 0;
}