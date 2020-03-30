#include <stdio.h>
#include <stack>
using namespace std;
bool fastScan(long long &x) {
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
    long long n, w, wi, li, s;
    while(fastScan(w)){
        s = 0;
        fastScan(n);
        while(n--){
            fastScan(wi);
            fastScan(li);
            s += wi * li;
        }
        long long ans = s / w;
        stack<int> ss;
        
        while(ans > 0){
            ss.push(ans % 10);
            ans /= 10;
        }

        while(!ss.empty()){
            putchar(ss.top() + '0');
            ss.pop();
        }
        putchar('\n');

    }
    return 0;
}