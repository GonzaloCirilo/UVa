#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
int main(){
    int n, x;
    int cont = 1;
    while(scanf("%d", &n) != EOF){
        vector<int>arr;
        for(int i = 0; i < n; i++){
            scanf("%d", &x);
            arr.push_back(x);
        }
        long long int ans = arr[0];
        for(int i = 0; i < n; i++){
            long long int m = arr[i];
            for(int j = i + 1; j < n; j++){
                ans = max(ans, m);
                m *= arr[j];
            }
            ans = max(ans, m);
        }
        if (ans < 0) ans = 0;
        printf("Case #%d: The maximum product is %lld.\n\n", cont++, ans);
    }
    return 0;
}