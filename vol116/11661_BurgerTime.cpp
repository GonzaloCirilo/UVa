#include <stdio.h>
#include <algorithm>
#include <math.h>
using namespace std;
int main(){
    int l; char c;
    while (scanf("%d\n", &l) && l){
        int ans = 200003, lastR = -1, lastD = -1, count = 1;
        while(l--){
            c = getchar();
            if(c == 'Z')
                ans = min(ans, 0);
            else if(c == 'R')
                lastR = count;
            else if(c == 'D')
                lastD = count;
            count++;
            if(lastD != -1 && lastR != -1)
                ans = min(ans, abs(lastD - lastR));
        }
        getchar();
        printf("%d\n", ans);

    }
    return 0;
}