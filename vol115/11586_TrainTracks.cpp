#include <stdio.h>
#include <math.h>
int main(){
    int t, contm, contf;
    scanf("%d\n", &t);
    while(t--){
        contm = 0, contf = 0;
        while(true){
            char c = getchar();
            if(c == '\n' || c == EOF) break;
            contm += (c == 'M');
            contf += (c == 'F');
        }
        if(abs(contm - contf) != 0 || (contf == 1 && contm == 1))
            printf("NO LOOP\n");
        else
            printf("LOOP\n");
    }
}