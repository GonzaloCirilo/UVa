#include <stdio.h>

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

int main(){
    int nLeaps[10000] = {};

    for(int i = 1; i < 10000; i++){
        nLeaps[i] += nLeaps[i - 1] + isLeapYear(i); 
    }


    int t, d1, m1, y1, d2, m2, y2;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        scanf("%d/%d/%d\n%d/%d/%d", &d1, &m1, &y1, &d2, &m2, &y2);

        printf("Case #%d: ", i);

        long long fd1 = y1 * 365 + dateToAccDays(m1 - 1, y1) + d1 + nLeaps[y1 - 1];
        long long fd2 = y2 * 365 + dateToAccDays(m2 - 1, y2) + d2 + nLeaps[y1 - 1];

        long long dif = fd1 - fd2;


        if(dif < 0){
            printf("Invalid birth date\n");
            continue;
        }

        long long years = dif / 365;

        // if(d2 == 29 && m2 == 2)
        //     years= dif / 366;

        if(years > 130){
            printf("Check birth date\n");
            continue;
        }

        printf("%lld\n", years);
        
    }
    return 0;
}