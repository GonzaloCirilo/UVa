#include <stdio.h>
#include <string>
using namespace std;

string months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
string days[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
string julianDays[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};
int monthThreshold[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

bool isInvalid(int d, int m, int y) {
    if(m == 2) {
        if (y < 1752) {
            return d > monthThreshold[m-1] + (y % 4 == 0);
        } else {
            return d > monthThreshold[m-1] + (y % 4 == 0 && y % 100 != 0 || y % 400 == 0);
        }
    } else {
        return d > monthThreshold[m-1];
    }
    return false;
}

// gauss algo/ math formula (calcMonthOffset included)
string calcDayNumFromDateGreg(int y, int m, int d){
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;

    //printf("%d %d %d %d %d %d ==", d, (13 * (mAux + 1) / 5), k, k / 4, j / 4, 5 * j);
    int day = (d + (13 * (m + 1) / 5) + k + (k/4) + (j/4) - (2*j)) % 7;
    if (day < 0) {
        day += 7;
    }
    return days[day];
}

// gauss algo/ math formula (calcMonthOffset included)
string calcDayNumFromDateJulian(int y, int m, int d){
    if (m == 1 || m == 2) {
        m += 12;
        y--;
    }
    int k = y % 100;
    int j = y / 100;

    //printf("%d %d %d %d %d %d %d ==", d, (13 * (m + 1) / 5), k, k / 4, j / 4, 5 * j, 5);
    int day = (d + (13 * (m + 1) / 5) + k + (k/4) + 5 - j) % 7;
    if (day < 0) {
        day += 7;
    }
    return julianDays[day];
}

int main() {
    int d, m, y;
    while(scanf("%d %d %d", &m, &d, &y) && (d != 0 || m != 0 || y != 0)) {
        if (m > 12 || m < 0 || d < 0 || isInvalid(d, m, y)) {
            printf("%d/%d/%d is an invalid date.\n", m, d, y);
            continue;
        }
        if(y == 1752 && m == 9 && d > 2 && d < 14) {
            printf("%d/%d/%d is an invalid date.\n", m, d, y);
            continue;
        }
        string day = "";
        if(y < 1752 || (y == 1752 && (m < 9 || (m == 9 && d <= 2)))) {
            day = calcDayNumFromDateJulian(y, m, d);
        } else {
            day = calcDayNumFromDateGreg(y, m, d);
        }

        printf("%s %d, %d is a %s\n", months[m-1].c_str(), d, y, day.c_str());
    }
    return 0;
}