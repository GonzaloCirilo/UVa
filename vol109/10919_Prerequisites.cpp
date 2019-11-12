#include <stdio.h>
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
    int k, m, ki;
    while (fastScan(k) && k){
        fastScan(m);
        bool courses[10000] = {};
        for(int i = 0; i < k; i++){
            fastScan(ki);
            courses[ki] = true;
        }
        bool ans = true;
        for(int i = 0; i < m; i++){
            int c, r, ci;
            fastScan(c);
            fastScan(r);
            for(int j = 0; j < c; j++){
                fastScan(ci);
                r -= (int)(courses[ci]);
            }
            ans = ans && r <= 0;
        }
        if(ans)
            printf("yes\n");
        else
            printf("no\n");
    }
    
    return 0;
}