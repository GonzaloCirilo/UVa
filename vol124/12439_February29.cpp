#include <stdio.h>
#include <string>
using namespace std;

bool isLeapYear(int n){
    return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
} 

int main(){

    // int nLeaps[1000000001] = {};

    // for(int i = 1; i < 1000000001; i++){
    //     nLeaps[i] += nLeaps[i - 1] + isLeapYear(i);
    // }

    string months[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};

    int t;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++){
        int d1, y1, d2, y2;
        char cm1[10] = {}, cm2[10] = {};
        scanf("%s %d, %d\n", cm1, &d1, &y1);
        scanf("%s %d, %d\n", cm2, &d2, &y2);
        string sm1 = string(cm1), sm2 = string(cm2);
        int m1, m2;

        for(int j = 0; j < 12; j++){
            if(months[j] == sm1)
                m1 = j + 1;
            if(months[j] == sm2)
                m2 = j + 1;
        }

        int ans = y2/4 - y2/100 + y2/400 - y1/4 + y1/100 - y1/400;

        if((m2 < 2 || (m2 == 2 && d2 < 29)) && isLeapYear(y2)){
            ans--;
        }

        if((m1 < 2 || (m1 == 2 && d1 <= 29)) && isLeapYear(y1)){
            ans++;
        }

        printf("Case %d: %d\n", i, ans);

    }
    return 0;
}