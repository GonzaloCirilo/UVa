#include <stdio.h>

int nLeaps[10000] = {};

bool isLeapYear(int n){
    return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
} 

long long dateToAccDays(int dd, int month, int yyyy){// values from 0 to 11 inclusive
    long long days = dd;
    switch (month - 1){
    case 11:
        days += 30;
    case 10:
        days += 31;
    case 9:
        days += 30;
    case 8:
        days += 31;
    case 7:
        days += 31;
    case 6:
        days += 30;
    case 5:
        days += 31;
    case 4:
        days += 30;
    case 3:
        days += 31;
    case 2:
        days += 28;
    case 1:
        days += 31;

    }
    if(isLeapYear(yyyy) && month > 2)
        days++;

    days += yyyy * 365 + nLeaps[yyyy - 1];
    return days;

}

int main(){

    for(int i = 1; i < 10000; i++){
        nLeaps[i] += nLeaps[i - 1] + isLeapYear(i); 
    }

    int n;
    while(scanf("%d", &n) && n){
        int d, m, y, q, pq, ans = 0, cont = 0;
        long long prev, act;
        scanf("%d %d %d %d", &d, &m, &y, &q);
        prev = dateToAccDays(d, m, y), pq = q;
        for(int i = 0; i < n - 1; i++){
            scanf("%d %d %d %d", &d, &m, &y, &q);
            act = dateToAccDays(d, m, y);
            if(act - prev == 1){
                ans += q - pq;
                cont++;
            }
            prev = act;
            pq = q;
        }
        printf("%d %d\n", cont, ans);
    }
    return 0;
}