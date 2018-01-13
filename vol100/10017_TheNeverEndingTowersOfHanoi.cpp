#include <stdio.h>
#include <stack>
#include <vector>
using namespace std;
int cont, n, m, t = 1;
vector<int>A, B, C;
void print() {
	if (cont > m)
		return;
	printf("A=>");
	for (int i = 0; i < A.size(); i++) {
		if (i == 0)
			printf("  ");
		printf(" %d", A[i]);
	}
	printf("\nB=>");
	for (int i = 0; i < B.size(); i++) {
		if (i == 0)
			printf("  ");
		printf(" %d", B[i]);
	}
	printf("\nC=>");
	for (int i = 0; i < C.size(); i++) {
		if (i == 0)
			printf("  ");
		printf(" %d", C[i]);
	}
	printf("\n\n");
	cont++;
}
void hanoi(int n, vector<int> &a, vector<int> &b, vector<int>&c) {
	if (cont > m)
		return;
	if (n == 1) {
		c.push_back(*(a.end()-1));
		a.pop_back();
		print();
		return;
	}
	hanoi(n - 1, a, c, b);
	//print();
	c.push_back(*(a.end() - 1));
	a.pop_back();
	print();
	hanoi(n - 1, b, a, c);
}
int main()
{
	while (true) {
		scanf("%d %d", &n, &m);
		if (n == 0 && m == 0)break;
		A = vector<int>(n);
		C.clear();
		B.clear();
		cont = 0;
		for (int i = 0; i < n; i++) {
			A[i] = n - i;
		}
		printf("Problem #%d\n\n", t);
		print();
		hanoi(n, A, B, C);
		t++;
	}
	return 0;
}
