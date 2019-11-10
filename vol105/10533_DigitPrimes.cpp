#include <stdio.h>
#include <vector>
#include <queue>
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

vector<bool> notPrime = vector<bool>(1000003, false);

void createSieve(){
    for(int p = 2; p * p <= 1000001; p++){
        if(!notPrime[p]){
            for(int i = p * p; i <= 1000001; i += p)
                notPrime[i] = true;
        }
    }
}

bool isDigitPrime(int n){
    int result = 0;
        while(n > 0){
            result += n % 10;
            n /= 10;
        }
    
    return !notPrime[result];
}

int main() {
    createSieve();
    vector<int> prefixSum = vector<int>(1000003, 0);
    for(int i = 2; i < 1000001; i++){
        prefixSum[i] = prefixSum[i-1] + (int)(isDigitPrime(i) && !notPrime[i]);
    }
    int n, t1, t2;
    fastScan(n);
    while(n--){
        fastScan(t1);
        fastScan(t2);
        printf("%d\n", prefixSum[t2] - prefixSum[t1-1]);
    }
    return 0;
}