#include <stdio.h>
#include <math.h>
int main(){
    int n;
    bool ended = false;
    while(!ended){
        n = 0;
        int aux = 0;
        while(true){
            char c = getchar();
            if(c == '\n') break;
            if(c == EOF){
                ended = true;
                break;
            }
            aux++;
            n *= 10;
            n += c - '0';
        }

        if(ended && aux == 0)
            break;
        
        int time[4] = {};
        int cont = 0;
        while(n){
            time[cont++] = n % 100;
            n /= 100;
        }
        long long totalInCC = time[0] + time[1] * 100 + time[2] * 6000 + time[3] * 360000;
        //for hours conversion rate 10 / (100 * 60 * 60 * 24)
        time[3] = totalInCC / 864000;
        totalInCC %= 864000;
        //for minutes conversion rate 1000 / (100 * 60 * 60 * 24)
        time[2] = totalInCC / 8640;
        totalInCC %= 8640;
        //for seconds conversion rate 100000 / (100 * 60 * 60 * 24)
        time[1] = totalInCC*10 / 864;
        totalInCC *= 10;
        totalInCC %= 864;
        //for CC conversion rate 100000 / (100 * 60 * 60 * 24)
        time[0] = totalInCC * 100 / 864;
        printf("%d%02d%02d%02d\n", time[3], time[2], time[1], time[0]);
    }
    return 0;
}