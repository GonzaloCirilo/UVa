#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

long long fact[21] = {};

void calcFact() {
	fact[1] = 1;
	fact[0] = 1;
	for (int i = 2; i <= 20; i++) {
		fact[i] = i * fact[i - 1];
	}
}

// calculates the smallest lexicographical permutation of an ordered string
// for n = 1 it will be the same string
string kPermutation(string s, long long n) {
	int start = s.length() - 1;
	string aux = "";
	while (!s.empty()) {
		int index = n / fact[start];
		long long res = n % fact[start];
		if (res == 0) {
			index--;
			res = fact[start];
		}
		n = res;
		aux.push_back(s.at(index));
		s.erase(s.begin() + index);
		start--;
	}
	return aux;
}

int main() {
	calcFact();
	int t;
	long long n;
	string s;
	cin >> t;
	while (t--) {
		cin >> s >> n;
		sort(s.begin(), s.end());
		cout << kPermutation(s, n + 1) << endl;
	}
	return 0;
}