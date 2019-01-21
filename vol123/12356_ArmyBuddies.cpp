#include <stdio.h>
struct Pos {
	int prev, next;
};
bool fastscan(int &x) {
	bool neg = false;
	int c;
	bool end = (c = getchar()) == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
int main() {
	Pos soldiers[100003];
	int b, s, lb, ub;
	while (scanf("%d %d\n", &s, &b) && s && b) {
		for (int i = 1; i <= s; i++) {
			soldiers[i].prev = i - 1;
			soldiers[i].next = i + 1;
		}
		while (b--) {
			fastscan(lb);
			fastscan(ub);
			if (soldiers[lb].prev == 0)
				printf("* ");
			else
				printf("%d ", soldiers[lb].prev);
			if(soldiers[ub].next > s)
				printf("*\n");
			else
				printf("%d\n", soldiers[ub].next);
			soldiers[soldiers[lb].prev].next = soldiers[ub].next;
			soldiers[soldiers[ub].next].prev = soldiers[lb].prev;
		}
		printf("-\n");
	}
	
	return 0;
}