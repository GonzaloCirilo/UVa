#include <stdio.h>
#include <queue>
using namespace std;
int main(){
    char c;
    int n;
    while(true){
        c = getchar();
        queue<int> q;
        if(c - '0' == 0) break;
        int cont = 0;
        while(c != '\n'){
            q.push(c - '0');
            cont++;
            c = getchar();
        }
        long long ans = 0;
        while(cont){
            int digit = q.front(); q.pop();
            ans += digit * ((1 << cont) -  1);
            cont--;
        }
        printf("%lld\n", ans);
    }
    return 0;
}