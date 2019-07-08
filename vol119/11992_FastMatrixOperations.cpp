#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> ii;
int start, ending;
bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
struct Node {
	long long min, max, sum;
};
void updateChildsDiff(vector<Node> &segment, vector<ii> &lazy, int pos, int l, int r, int isSum, int diff) {
	if (isSum == 1) {// 1 for adding
		segment[pos].min += diff;
		segment[pos].max += diff;
		segment[pos].sum += (r - l + 1)*diff;
		if (l != r) {
			lazy[2 * pos + 1].first += diff;
			lazy[2 * pos + 2].first += diff;
			lazy[2 * pos + 1].second = lazy[2 * pos + 1].second == 2 ? 2 : isSum;
			lazy[2 * pos + 2].second = lazy[2 * pos + 1].second == 2 ? 2 : isSum;
		}
	}
	else if (isSum == 2) {// 2 for setting value
		segment[pos].min = diff;
		segment[pos].max = diff;
		segment[pos].sum = (r - l + 1)*diff;
		if (l != r) {
			int mid = (l + r) / 2;
			lazy[2 * pos + 1].first = diff;
			lazy[2 * pos + 2].first = diff;
			lazy[2 * pos + 1].second = isSum;
			lazy[2 * pos + 2].second = isSum;
		}
	}
}
void propagate(vector<Node> &segment, vector<ii> &lazy, int pos, int l, int r) {
	if (lazy[pos].first != 0 && lazy[pos].second != 0) {// if true there is pending operation
		updateChildsDiff(segment, lazy, pos, l, r, lazy[pos].second,lazy[pos].first);
		lazy[pos] = { 0,0 };
	}
}
// l = 0, r = max array value, start = start of the range, end = end of the range
void updateSegmentTree(vector<Node> &segment, vector<ii> &lazy, int l, int r, int pos, int diff, int isSum) {
	if (l > r)
		return;
	propagate(segment, lazy, pos, l, r);

	if (start > r || ending < l)
		return;

	if (start <= l && ending >= r) {
		updateChildsDiff(segment, lazy, pos, l, r, isSum, diff);
		return;
	}
	int mid = (l + r) / 2;
	updateSegmentTree(segment, lazy, l, mid, 2 * pos + 1, diff, isSum);
	updateSegmentTree(segment, lazy, mid + 1, r, 2 * pos + 2, diff, isSum);
	segment[pos].min = min(segment[2 * pos + 1].min, segment[2 * pos + 2].min);
	segment[pos].max = max(segment[2 * pos + 1].max, segment[2 * pos + 2].max);
	segment[pos].sum = segment[2 * pos + 1].sum + segment[2 * pos + 2].sum;

}
Node rangeQuery(vector<Node> &segment, vector<ii> &lazy, int l, int r, int pos) {
	if (l > r)
		return Node{9999999999,-1,0 };

	propagate(segment, lazy, pos, l, r);

	if (start > r || ending < l)
		return Node{ 9999999999,-1,0 };

	if (start <= l && ending >= r) {
		return segment[pos];
	}
	int mid = (l + r) / 2;
	Node left = rangeQuery(segment, lazy, l, mid, 2 * pos + 1);
	Node right = rangeQuery(segment, lazy, mid + 1, r, 2 * pos + 2);
	return Node{
		min(left.min, right.min),
		max(left.max, right.max),
		left.sum + right.sum
	};
}
int main() {
	int r, c, m, mi, x1, y1, x2, y2, v;
	vector<vector<Node>> segTree;
	vector<vector<ii>> lazy;
	while (/*scanf("%d %d %d\n", &r, &c, &m) != EOF*/fastScan(r)) {
		fastScan(c);
		fastScan(m);
		segTree = vector<vector<Node>>(r, vector<Node>(3 * c));
		lazy = vector<vector<ii>>(r, vector<ii>(3 * c, { 0,0 }));
		while (m--) {
			fastScan(mi);
			fastScan(x1);
			fastScan(y1);
			fastScan(x2);
			fastScan(y2);
			x1--, x2--, y1--, y2--;
			if (mi < 3)
				fastScan(v);
			start = y1, ending = y2;
			switch (mi) {
			case 1:
				for (int i = x1; i <= x2; i++) {
					updateSegmentTree(segTree[i], lazy[i], 0, c, 0, v, 1);
				}
				break;
			case 2:
				for (int i = x1; i <= x2; i++) {
					updateSegmentTree(segTree[i], lazy[i], 0, c, 0, v, 2);
				}
				break;
			case 3:
				auto no = Node{ 9999999999, -1, 0 };
				
				for (int i = x1; i <= x2; i++) {
					auto q = rangeQuery(segTree[i], lazy[i], 0, c, 0);
					if (no.max < q.max)
						no.max = q.max;
					if (no.min > q.min)
						no.min = q.min;
					no.sum += q.sum;
				}
				printf("%lld %lld %lld\n", no.sum, no.min, no.max);
				break;
			}
		}
	}
	return 0;
}