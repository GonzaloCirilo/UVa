#include <stdio.h>

bool isLeapYear(int n){
    return n % 4 == 0 && n % 100 != 0 || n % 400 == 0;
} 

int dateToAccDays(int dd, int month, int yyyy){// values from 0 to 11 inclusive
    int days = dd;
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
    dd = acc; mm = i + 1;
}

void addDaysTodate(int &dd, int &mm, int &yy, int q){
    int daysP = dateToAccDays(dd, mm, yy);

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
}

void printZodiacSign(int mm, int dd){
    if(mm == 2 && dd == 29){
        printf("pisces\n");
        return;
    }

    int days = dateToAccDays(dd, mm, 1);

    if(days >= dateToAccDays(21, 1, 1) && days <= dateToAccDays(19, 2, 1)){
        printf("aquarius\n");
    }else if(days >= dateToAccDays(20, 2, 1) && days <= dateToAccDays(20, 3, 1)){
        printf("pisces\n");
    }else if(days >= dateToAccDays(21, 3, 1) && days <= dateToAccDays(20, 4, 1)){
        printf("aries\n");
    }else if(days >= dateToAccDays(21, 4, 1) && days <= dateToAccDays(21, 5, 1)){
        printf("taurus\n");
    }else if(days >= dateToAccDays(22, 5, 1) && days <= dateToAccDays(21, 6, 1)){
        printf("gemini\n");
    }else if(days >= dateToAccDays(22, 6, 1) && days <= dateToAccDays(22, 7, 1)){
        printf("cancer\n");
    }else if(days >= dateToAccDays(23, 7, 1) && days <= dateToAccDays(21, 8, 1)){
        printf("leo\n");
    }else if(days >= dateToAccDays(22, 8, 1) && days <= dateToAccDays(23, 9, 1)){
        printf("virgo\n");
    }else if(days >= dateToAccDays(24, 9, 1) && days <= dateToAccDays(23, 10, 1)){
        printf("libra\n");
    }else if(days >= dateToAccDays(24, 10, 1) && days <= dateToAccDays(22, 11, 1)){
        printf("scorpio\n");
    }else if(days >= dateToAccDays(23, 11, 1) && days <= dateToAccDays(22, 12, 1)){
        printf("sagittarius\n");
    }else{
        printf("capricorn\n");
    }



}

int main(){
    int t, dd, mm, yy;
    scanf("%d\n", &t);
    for(int i = 1; i <= t; i++){
        int a = getchar() - '0', b = getchar() - '0';
        mm = a * 10 + b;
        a = getchar() - '0', b = getchar() - '0';
        dd = a * 10 + b;
        a = getchar() - '0', b = getchar() - '0';
        yy = a * 10 + b;
        yy *= 100;
        a = getchar() - '0', b = getchar() - '0';
        yy += a * 10 + b;

        addDaysTodate(dd, mm, yy, 40 * 7);

        printf("%d %02d/%02d/%04d ", i, mm, dd, yy);

        printZodiacSign(mm, dd);
        getchar();

    }

    return 0;
}