#include <iostream>
#include <string>

using namespace std;

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

int main(){
    int ts, k;
    cin >> ts;
    string months[12] = {"January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"};
    string line;
    for(int t = 1; t <= ts; t++){
        cin >> line >> k;
        int y, d; char cm[15];
        sscanf(line.c_str(), "%d-%s", &y, cm);
        string ssm = string(cm), sm = string(ssm.begin(), ssm.end() - 3);
        d = (ssm[ssm.size()-2] - '0') * 10 + (ssm[ssm.size()-1] - '0');
        
        
        int m;
        for(int i = 0; i < 12; i++){
            if(months[i] == sm){
                m = i + 1;
                break;
            }
        }
        addDaysTodate(d, m, y, k);

        printf("Case %d: %d-%s-%02d\n", t, y, months[m - 1].c_str(), d);
    }

    return 0;
}