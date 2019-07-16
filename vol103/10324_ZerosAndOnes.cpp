#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int start, ending;
pair<int, int> construct(vector<int> &data, int l, int r, vector<pair<int, int>>&st, int pos) {
	if (l == r) {
		st[pos] = { data[l], 1 };
		return st[pos];
	}
	int mid = (l + r) / 2;
	auto left = construct(data, l, mid, st, pos * 2 + 1);
	auto right = construct(data, mid + 1, r, st, pos * 2 + 2);
	if ((left.first == right.first) && left.second && right.second) {
		st[pos] = { left.first, left.second };
	}
	else {
		st[pos] = { -1,0 };
	}
	return st[pos];
}
pair<int, int> rangeQuery(vector<pair<int, int>> &segment, int l, int r, int pos) {
	if (l > r)
		return { -2,0 };


	if (start > r || ending < l)
		return { -2, 0 };

	if (start <= l && ending >= r) {
		return segment[pos];
	}
	int mid = (l + r) / 2;
	auto left = rangeQuery(segment, l, mid, 2 * pos + 1);
	auto right = rangeQuery(segment, mid + 1, r, 2 * pos + 2);
	if (left.first == -2) {
		return  right;
	}
	else if (right.first == -2) {
		return left;
	}
	else if (left.second == 0 || right.second == 0) {
		return { -1,0 };
	}
	else if ((left.first == right.first) && left.second && right.second) {
		return left;
	}
	else {
		return { -1,0 };
	}
}
int main() {
	int n, i, j;
	int ca = 1;
	while (true) {
		char c = getchar();
		if (c == EOF) break;
		printf("Case %d:\n", ca);
		vector<int> s;
		s.push_back(c - '0');
		while (true) {
			c = getchar();
			if (c == EOF || c == '\n') break;
			s.push_back(c - '0');
		}
		vector<pair<int, int>> st = vector<pair<int, int>>(4*s.size() + 1);
		construct(s, 0, s.size() - 1, st, 0);
		scanf("%d\n", &n);
		for (int k = 0; k < n; k++) {
			scanf("%d %d\n", &i, &j);
			start = min(i, j);
			ending = max(i, j);
			auto ans = rangeQuery(st, 0, s.size() - 1, 0);
			if (ans.second)
				printf("Yes\n");
			else
				printf("No\n");
		}
		ca++;
	}

	return 0;
}