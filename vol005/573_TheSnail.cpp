#include <stdio.h>
int simulate(float h, float u, float d, float f){  
    float acd = 0.0, dropRate = (f/100) * u;
    int cont = 1;
    while (true){
        acd += u;
        if(acd > h) return cont;
        acd -= d;
        u -= dropRate;
        if(u < 0) u = 0;
        if(acd < 0) return -cont;
        cont++;
    }
}

int main(){
    float  h, u, d, f;
    while (scanf("%f %f %f %f", &h, &u, &d, &f) && h) {
        int ans = simulate(h,u,d,f);
        if(ans > 0)
            printf("success on day %d\n", ans);
        else
            printf("failure on day %d\n", -ans);
    }    
    return 0;
}