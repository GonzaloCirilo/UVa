#include <stdio.h>
#include <algorithm>
using namespace std;

bool isLeapYear(int n){
    return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
} 

int dateToAccDays(int month, int yyyy){// values from 0 to 11 inclusive
    int days = 0;
    switch (month - 1){
    case 10:
        days += 30;
    case 9:
        days += 31;
    case 8:
        days += 30;
    case 7:
        days += 31;
    case 6:
        days += 31;
    case 5:
        days += 30;
    case 4:
        days += 31;
    case 3:
        days += 30;
    case 2:
        days += 31;
    case 1:
        days += 28;
    case 0:
        days += 31;

    }
    if(isLeapYear(yyyy) && month > 1)
        days++;
    return days;

}
int daysOfM[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void accDaysToDate(int acc, int &dd, int &mm, int yy){
    dd = 1; mm = 0;
    int i;
    for(i = 0; i < 12; i++){
        if(acc <= daysOfM[i] + (isLeapYear(yy) && i == 1)){
            break;
        }
        acc -= daysOfM[i] + (isLeapYear(yy) && i == 1);

    }
    dd = acc; mm = i;
}

int main(){

    long long q;
    int dd, mm, yy;
    while(scanf("%lld %d %d %d", &q, &dd, &mm, &yy) && (dd || mm || yy)){
        mm--;
        int daysP = dd + dateToAccDays(mm, yy);

        int daysInYear = 365 + isLeapYear(yy);

        if(q + daysP > daysInYear){
            q -= (daysInYear - daysP);
            yy++;
            daysInYear = 365 + isLeapYear(yy);

            while(q > daysInYear){
                q -= daysInYear;
                yy++;
                daysInYear = 365 + isLeapYear(yy);
            }

            accDaysToDate(q, dd, mm, yy);


        } else {
            daysP += q;
            accDaysToDate(daysP, dd, mm, yy);
        }

        printf("%d %d %d\n", dd, mm + 1, yy);
    }

    return 0;
}