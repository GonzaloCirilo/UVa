#include <stdio.h>
#include <math.h>
typedef unsigned long long ull;

int main(){
    int k, m;
    /* From the problem we know that for 1 (k = 1) sec of slow each day we will have the correct time (m = 0)
       every 43200 days. Thus, this is the maximun number of days it will require. Thus the formula
       should be (43200 / abs(k-m)) * ((86400 - k) / 60). The first part is a simple division since 
       the bigger is the diff of the slow, the less days it will take to happen. The second part its the
       conversion it till the conversion of days to minutes taking into consideration either k ot m sinice we need to
       display the hour in the faulty clocks. Simpifying the expression we obtain the following formula
       shown in the time variable. Finally we add 0.5 to handle the rounding.
    */
    while (scanf("%d %d", &k, &m) != EOF) {
        int time = 720 * (86400 - k) * 1.0 / abs(k - m) + 0.5, h = (time / 60) % 12, min = time % 60;
        printf("%d %d %02d:%02d\n", k, m, h == 0 ? 12 : h, min);
    }
    
    return 0;
}