#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
    long long aux, i;
    while (b != 0) {
        aux = a % b;
        a = b;
        b = aux;
    }
    return a;
}

int main() {
    int x;
    while (scanf("%d", &x) != EOF && x) {
        vector<int> arr;
        arr.push_back(x);
        while (scanf("%d", &x)) {
            if (!x) break;
            arr.push_back(x);
        }
        long long ans = 0;
        for(int i = 1; i < arr.size(); i++) {
            ans = gcd(ans, arr[i] - arr[i-1]);
        }
        if (ans < 0) ans *= -1;
        printf("%lld\n", ans);
        
    }
    return 0;
}