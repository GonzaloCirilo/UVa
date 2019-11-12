#include <stdio.h>
#include <algorithm>
using namespace std;

int reduceToOneDigit(int n){
    while(n/10 >= 1){
        int res = 0;
        while(n > 0){
            res += n % 10;
            n /= 10;
        }
        n = res;
    }
    return n;
}

int main(){
    char c;
    while(true){
        int sum = 0;
        do{
            c = getchar();
            if(c == '\n' || c == EOF)  break;
            if(c >= 'a' && c <= 'z')
                sum += c - 'a' + 1;
            else if(c >= 'A' && c <= 'Z')
                sum += c - 'A' + 1; 
        }while (true);
        
        if(sum == 0) break;
        int a = reduceToOneDigit(sum);
        int sum2 = 0;

        do{
            c = getchar();
            if(c == '\n' || c == EOF)  break;
            if(c >= 'a' && c <= 'z')
                sum2 += c - 'a' + 1;
            else if(c >= 'A' && c <= 'Z')
                sum2 += c - 'A' + 1; 
        }while (true);
        int b = reduceToOneDigit(sum2);

        int num = min(a,b), den = max(a,b);
        float ans = (num * 1.0 / den) * 100;
        printf("%.2f %%\n", ans);
    }
    return 0;
}