#include <stdio.h>

int sumDigits(int x) {
    int sum = 0;
    while (x) {
        sum += x % 10;
        x /= 10;
    }
    return sum;
}

int oddDigitSum(int x) {
    //printf("%d %d\n", 2 * (x / 1000), 2 * ((x / 10) % 10));
    return sumDigits(2 * (x / 1000)) + sumDigits(2 * ((x / 10) % 10));
}

int evenDigitSum(int x) {
    return sumDigits((x / 100) % 10) + sumDigits(x % 10);
}

int main() {
    int t, p1, p2, p3, p4;
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d %d", &p1, &p2, &p3, &p4);
        int odd = oddDigitSum(p1) + oddDigitSum(p2) + oddDigitSum(p3) + oddDigitSum(p4);
        int even = evenDigitSum(p1) + evenDigitSum(p2) + evenDigitSum(p3) + evenDigitSum(p4);
        //printf("%d\n", odd + even);
        if ((odd + even) % 10 == 0) {
            printf("Valid\n");
        } else {
            printf("Invalid\n");
        }
    }
    return 0;
}