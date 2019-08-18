#include <stdio.h>
#include <algorithm>
using namespace std;
bool fastScan(int &x) {
	bool neg = false;
	int c;
    do{
        c = getchar();
    }while (c == '\n');

	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58) ; c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}
int main(){

    int n;
    int prefix[10001], arr[10001];
    while(fastScan(n) && n){
        for(int i = 0; i< n; i++){
            fastScan(arr[i]);            
        }
        prefix[0] = arr[0];
        for(int i = 1; i< n; i++){
            prefix[i] = prefix[i-1] + arr[i];
        }

        int min_pre = 0;
        int ans = -999999;
        for (int i = 0; i < n; i++) { 
            ans = max(ans, prefix[i] - min_pre); 
            min_pre = min(min_pre, prefix[i]); 
        } 
        if(ans > 0){
            printf("The maximum winning streak is %d.\n", ans);
        }else{
            printf("Losing streak.\n");
        }
    }
    
    return 0;
}