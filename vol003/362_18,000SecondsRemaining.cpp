#include <stdio.h>
#include <math.h>

int main() {
    int t = 1;
    while(true) {
        int size, progress;
        scanf("%d", &size);
        if (size == 0) break;
        printf("Output for data set %d, %d bytes:\n", t++, size);

        int count = 0, acc = 0, time = 0;
        while(size > 0) {
            scanf("%d", &progress);
            count++;
            acc += progress;
            size -= progress;
            if(count == 5) {
                if (acc == 0) {
                    printf("   Time remaining: stalled\n");
                } else {
                    int remaining = size * 5/ acc;
                    bool hasFraction = (size*5) % acc != 0;
                    if (hasFraction) remaining++;
                    printf("   Time remaining: %d seconds\n", remaining);
                }
                count = 0;
                acc = 0;
            }
            time++;
        }
        printf("Total time: %d seconds\n\n", time);
    }
    return 0;
}