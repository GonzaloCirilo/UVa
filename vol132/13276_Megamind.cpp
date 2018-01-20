// TestGrounds.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <math.h>
#include <stdint.h>
int main() {
	int t;
	int64_t e, p, r, k;
	scanf("%d", &t);
	for (int i = 0; i<t; i++) {
		scanf("%lld %lld %lld %lld", &e, &p, &k, &r);
		int64_t ans;
		if ((r > p*k &&  e > p*k) || (r == p*k && e > p*k)) {
			ans = -1;
			printf("Case %d: %lld\n", i + 1, ans);
			continue;
		}
		if (!(p*k < e)) {
			ans = ceil((double)e / p);
			printf("Case %d: %lld\n", i + 1, ans);
			continue;
		}

		int64_t ed = e - p*k, round = p*k - r;
		//ans = (ed / round)*k + k*(ceil((double)(e-ed/round*round-p*k)/round))+ceil((double)(e - ed / round*round -round*ceil((double)(e - ed / round*round - p*k) / round))/p);
		ans = (ed / round)*k;
		e -= ed / round*round;
		int64_t time = ceil((double)(e - p*k) / round);
		e -= (round)*(time);
		ans += (k)*time;
		ans += ceil((double)e / p);
		printf("Case %d: %lld\n", i + 1, ans);
	}
	return 0;
}
/*
21
16482 5 5 5
86252 3 3 3
100000 3 3 3
100000 7 7 7
4531 6 6 6
21 4 4 4
10 3 3 3
18 3 3 3
5 3 3 1	
10 3 3 2
2 2 2 2
16 4 4 16
2 1 12 50
7 3 3 50
300 99 10 50
16 4 6 100
100000 4 3 11
16 4 3 12
15 2 5 5
8 5 2 3
99 9 1 6
2 1 2 3
*/