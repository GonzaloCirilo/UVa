#include <stdio.h>// UVa 10453 Make Palindrome.cpp
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;
char st[1002], ans[2006];
bool bst[2006];
int dp[2006][2006], cont;
int len(int l, int r) {// starts from 0 to st lenght, recursive
	if (l == r || l > r)
		return dp[l][r] = 0;
	if (st[l] == st[r])
		return dp[l][r] = len(l + 1, r - 1);
	else
		return dp[l][r] = 1 + min(len(l + 1, r), len(l, r - 1));
}
int len() {//Iterative
	int lenght = strlen(st);
	bst[lenght - 1] = false;
	for (int i = lenght - 2; i >= 0; i--) {
		bst[i] = false;
		for (int j = i + 1; j < lenght; j++) {
			if (st[i] == st[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][lenght - 1];
}
void printPalindrome(int i, int j) {// recursive
	if (i > j)
		return;
	if (i == j) {
		ans[cont++] = st[j]; return;
	}
	else if (st[i] == st[j]) {
		ans[cont++] = st[i];
		printPalindrome(i + 1, j - 1);
		ans[cont++] = st[j];
	}
	else if (dp[i][j - 1] <= dp[i + 1][j]) {
		ans[cont++] = st[j];
		printPalindrome(i, j - 1);
		ans[cont++] = st[j];
	}
	else {
		ans[cont++] = st[i];
		printPalindrome(i + 1, j);
		ans[cont++] = st[i];
	}

}
int main() {
	for (int i = 0; i < 2006; i++) {
		dp[i][i] = 0;
	}
	while (scanf("%s", st) != EOF) {
		cont = 0;
		printf("%d ", len());
		// Make palindrome
		// printPalindrome();
		printPalindrome(0, strlen(st) - 1);
		ans[cont] = 0;
		printf("%s\n", ans);
	}
	return 0;
}
