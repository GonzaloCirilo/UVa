#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;
int main(){
    int n;
    vector<double> ans = vector<double>(1000001, 0), acc = ans;
    acc[1] = 1 * (1.0/2);
    ans[1] = log10(0.5) *-1;

    for(int i = 2; i < 1000001; i++){
        //printf("====%d %lf\n", i, (1.0 / i) * (1.0 / (i + 1)));
        ans[i] = (ans[i - 1] + (log10(1.0 / i) * -1) + (log10((1.0 / (i + 1))) * -1));
        acc[i] = (1 - acc[i - 1]) * (1.0 / i) * (1.0 / (i + 1)) + acc[i - 1];
    }

    while(scanf("%d", &n) != EOF){
        printf("%.6lf %lld\n", acc[n], (long long)floor(ans[n]));
    }
    
    return 0;
}