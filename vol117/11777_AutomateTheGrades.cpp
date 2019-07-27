#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    int a, b, c, d, s[3], t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        printf("Case %d: ", i);
        scanf("%d %d %d %d %d %d %d", &a, &b, &c, &d, &s[0], &s[1], &s[2]);
        sort(s, s + 3);
        int ans = a + b + c + d + ((s[1] + s[2]) / 2);
        if(ans >= 90){
            printf("A\n");
        }else if(ans >= 80){
            printf("B\n");
        }else if(ans >= 70){
            printf("C\n");
        }else if(ans >= 60){
            printf("D\n");
        }else{
            printf("F\n");
        }
        
    }

}