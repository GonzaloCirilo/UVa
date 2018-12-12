#include <stdio.h>
#include <map>
using namespace std;
int read() {
	char rune; int token;
	auto ss = scanf("%d", &token);
	if (ss != 1) {//is a char
		scanf("%c", &rune);
		token = (int)rune - 'A' + 1;
	}
	else {
		token += 4;
	}
	return token;
}
void compare(char right, char left, bool &failure, map <int, char>&hash) {
	if (right < 5 && left < 5) {
		failure = right != left;
		return;
	}
	if (right < left && right < 5) {
		auto res = hash.insert({ left - 4,(char)(right + 'A' - 1) });
		if (res.second == false && hash[left - 4] != (char)(right + 'A' - 1)) {
			failure = true;
		}
	}
	else if (right > left && left < 5) {
		auto res = hash.insert({ right - 4,(char)(left + 'A' - 1) });
		if (res.second == false && hash[right - 4] != (char)(left + 'A' - 1)) {
			failure = true;
		}
	}
	else if (hash.find(right - 4) != hash.end()) {
		auto res = hash.insert({ left - 4,hash.find(right - 4)->second });
		if (res.second == false && hash[left - 4] != hash.find(right - 4)->second) {
			failure = true;
		}
	}
	else if (hash.find(left - 4) != hash.end()) {
		auto res = hash.insert({ right - 4,hash.find(left - 4)->second });
		if (res.second == false && hash[right - 4] != hash.find(left - 4)->second) {
			failure = true;
		}
	}
	return;
}
int main() {
	int l, tokens[201], tokens2[201], token, cont = 0;
	char rune;
	map <int, char> hash;
	bool failure;
	while (scanf("%d\n", &l) != EOF) {
		if (cont)
			printf("\n");
		failure = false;
		for (int i = 0; i < l; i++) {
			tokens[i] = read();
		}
		for (int i = 0; i < l; i++) {
			tokens2[i] = read();
			if (!failure) {
				compare(tokens2[i], tokens[i], failure, hash);
			}
		}
		for (int i = l - 1; i >= 0; i--) {
			if (!failure) {
				compare(tokens2[i], tokens[i], failure, hash);
			}
		}
		if (failure)
			printf("NO\n");
		else {
			printf("YES\n");
			for (map<int, char>::iterator it = hash.begin(); it != hash.end(); ++it)
				printf("%d %c\n", it->first, it->second);
		}
		hash.clear();
		cont++;
	}

	return 0;
}