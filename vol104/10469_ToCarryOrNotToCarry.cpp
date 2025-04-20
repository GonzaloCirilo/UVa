#include <stdio.h>
using namespace std;

int main() {
    unsigned long x, y;
    while (scanf("%ld %ld", &x, &y) != EOF) {
        printf("%ld\n", x ^ y);
    }
    return 0;
}