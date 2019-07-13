#include <stdio.h>
#include <string>
#include <iostream>
#include <unordered_map>
using namespace std;
int main() {
	int n;
	int cont = 0;
	while (scanf("%d\n", &n) != EOF) {
		int arr[10] = {};
		if (cont++ != 0)
			printf("\n");
		string names[10] = {};
		unordered_map<string, int> dict;
		for (int i = 0; i < n; i++) {
			string s;
			while (true) {
				char c = getchar();
				if (c == ' ' || c == '\n') break;
				s.push_back(c);
			}
			dict.insert({ s, i });
			names[i] = s;
		}
		string u, v;
		int k;
		for (int i = 0; i < n; i++) {
			int aux;
			cin >> u >> aux >> k;
			if(k)
				arr[dict[u]] += -(aux - (aux % k));
			for (int j = 0; j < k; j++) {
				cin >> v;
				arr[dict[v]] += aux / k;
			}
		}

		for (int i = 0; i < n; i++) {
			printf("%s %d\n", names[i].c_str(), arr[dict[names[i]]]);
		}
	}
}