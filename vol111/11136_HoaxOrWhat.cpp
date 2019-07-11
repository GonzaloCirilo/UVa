#include <stdio.h>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
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

int main(){
    int n, k, b;   
    while(scanf("%d\n", &n) && n != 0){
        long long ans = 0;
		multiset<int> v;
        while(n--){
            fastScan(k);
            while(k--){
                fastScan(b);
                v.insert(b);
            }
            ans += *(--v.end()) - *(v.begin());
			v.erase(v.begin());
			v.erase(--v.end());
        }
        printf("%lld\n", ans);
    }
}