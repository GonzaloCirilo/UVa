#include <string>
#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
int main() {
	string st;
	int n, ans[5] = { 76, 16, 56, 96, 36 };
	scanf("%d\n", &n);
	string::size_type sz;
	while (n) {
		cin >> st;
		if (st == "0" || st == "1")
			printf("%d\n", (int)pow(66, stoi(st)));
		else {
			int a = (st.length() > 1)? (st.at(st.length() - 2)-'0') * 10 + (st.at(st.length() - 1) - '0') :0 + (st.at(st.length() - 1) - '0');
			printf("%d\n", ans[a % 5]);
		}
		n--;
	}
	return 0;
}