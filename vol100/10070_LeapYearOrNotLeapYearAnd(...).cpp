#include <stdio.h>

bool isLeapYear(int two, int four){// evaluating last two and four digits accordingly
    return two % 4 == 0 && four % 100 != 0 || four % 400 == 0;
} 

bool isHuluculu(long long sumDigits, int lastDigit){
    return sumDigits % 3 == 0 && (lastDigit == 0  || lastDigit == 5);
}

bool isBulukulu(int lastDigit, long long sum11, int two, int four){
    return isLeapYear(two, four) && (lastDigit == 0  || lastDigit == 5) && sum11 % 11 == 0;
}

int main(){
    int n, t = 0;
    while(true){
        // for 2 and 4 divisibility
        int fd = 0, sd = 0, td = 0, qd = 0;

        // for 3  and 11 divisibility
        long long sum3 = 0, sum11 = 0;
        int aux = 1;

        char token = getchar();

        if(token == '\n' || token == EOF) break;
        if(t != 0) putchar('\n');

        qd = token - '0';
        sum3 += qd;
        sum11 += (qd * aux);
        aux *= -1;

        while(true){
            token = getchar();
            if(token == '\n') break;
            fd = sd;
            sd = td;
            td = qd;
            qd = token - '0';
            sum3 += qd;
            sum11 += (qd * aux);
            aux *= -1;
        }

        int twoDigits = td * 10 + qd, fourDigits = fd * 1000 + sd * 100 + twoDigits;

        //printf("===%d\n", fourDigits);
        if(isLeapYear(twoDigits, fourDigits)){
            printf("This is leap year.\n");
        }
        if(isHuluculu(sum3, qd)){
            printf("This is huluculu festival year.\n");
        }
        if(isBulukulu(qd, sum11, twoDigits, fourDigits)){
            printf("This is bulukulu festival year.\n");
        }
        if(!isLeapYear(twoDigits, fourDigits) &&
         !isHuluculu(sum3, qd) && 
         !isBulukulu(qd, sum11, twoDigits, fourDigits)){
            printf("This is an ordinary year.\n");
        }
        
        t++;
    }
    return 0;
}