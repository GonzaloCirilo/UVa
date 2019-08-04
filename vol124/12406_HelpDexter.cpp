#include <stdio.h>
int main(){
    int t, p, q;
    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d %d", &p, &q);
        long long max = 0, min = 999999999999999999;
        if(p == 1){
            if(q == 1)
                printf("Case %d: 2\n", i + 1);
            else
                printf("Case %d: impossible\n", i + 1);
            continue;
        }
        for(long long mask = 0; mask < (1 << (p - 1)); mask++){
            long long num = 0;
            for(int bit = 0; bit < p - 1; bit++){
                if((mask >> bit) & 1)
                    num *= 10, num += 2;
                else
                    num *= 10, num += 1;
            }
            num *= 10, num +=2;
            if(!(num % (1 << q))){
                if(num < min)
                    min = num;
                if(num > max)
                    max = num;
            }
        }

        printf("Case %d: ", i + 1);
        if(max == 0){
            printf("impossible\n");
        }else{
            if(max == min)
                printf("%lld\n", min);
            else
                printf("%lld %lld\n", min, max);
        }
        
    }
    return 0;
}