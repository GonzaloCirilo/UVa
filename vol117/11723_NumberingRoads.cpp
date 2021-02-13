#include <stdio.h>
#include <math.h>
using namespace std;

int main(){
    int n, r, c = 1;
    while(scanf("%d %d", &n, &r) && n && r){
        printf("Case %d: ", c++);
        int ans = ceil((double) n / r);
        if(ans > 27)
            printf("impossible\n"); 
        else
            printf("%d\n", (!ans? 0: ans - 1));
    }
    return 0;
}