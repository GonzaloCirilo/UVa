#include <stdio.h>
#include <math.h>

int main(){
    int t, n, rel[501];
    scanf("%d", &t);
    while (t--){
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &rel[i]);
        }
        int ans = 99999999;

        for(int i = 0; i < n; i++){
            int sum = 0;
            for(int j = 0; j < n; j++){
                sum += abs(rel[i] - rel[j]); 
            }
            if(sum < ans)
                ans = sum;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}