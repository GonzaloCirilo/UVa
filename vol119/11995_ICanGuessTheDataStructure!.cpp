#include <stdio.h>
#include <stack>
#include <queue>
#include <vector>
#include <functional>
using namespace std;
int main() {
	int n, c, x; bool bs = 1, bq = 1, bpq = 1;
	while (scanf("%d", &n) != EOF) {
		bs = 1, bq = 1, bpq = 1;
		stack<int> s; queue<int> q;
		priority_queue<int, vector<int>, less<int> >pq;
		for (int i = 0; i < n; i++) {
			scanf("%d %d", &c, &x);
			if (c == 1) {
				s.push(x); q.push(x); pq.push(x);
			}else{
				if (!s.empty()) {
					if (s.top() != x)bs = false;
					if (q.front() != x)bq = false;
					if (pq.top() != x)bpq = false;
					s.pop(); q.pop(); pq.pop();
				}
				else {
					bs = false;
					bq = false;
					bpq = false;
				}
			}
		}
		int count = 0;
		if (bs == 1)count++;
		if (bq == 1)count++;
		if (bpq == 1)count++;
		if (bs == 0 && bq == 0 && bpq == 0)
			printf("impossible\n");
		else if (count > 1)
			printf("not sure\n");
		else if (bs)
			printf("stack\n");
		else if (bq)
			printf("queue\n");
		else
			printf("priority queue\n");
	}
	return 0;
}
