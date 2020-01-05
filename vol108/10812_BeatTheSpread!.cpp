#include <stdio.h>
#include <algorithm>

using namespace std;

int main() {
    int t;
    long long s, d;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld %lld", &s, &d);
        long long a = (s + d) / 2;
        long long b = (s - d) / 2;
        if(d > s || (s + d) % 2 != 0 || (s - d) % 2 != 0) {
            printf("impossible\n");
            continue;
        }        
        printf("%d %d\n", max(a, b), min(a,b));
    }
    
    return 0;
}