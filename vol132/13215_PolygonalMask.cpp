#include <stdio.h>
#include <math.h>
int main(){
    int t, n;
    double k;
    char c;
    scanf("%d", &t);
    while(t--){
        scanf("%d\n", &n);
        bool horizontal = false;
        double b = 0, h = 0, houseArea = 0.0f;
        while(n--){
            scanf("%c %lf\n", &c, &k);
            switch(c){
                case 'C': 
                    if(horizontal)
                        b += k;
                    else
                        h += k ;
                    horizontal = !horizontal;
                    houseArea += k * k;
                    if(horizontal)
                        b += k;
                    else
                        h += k ;
                    break;
                case 'T':
                    if(horizontal)
                        b += k;
                    else
                        h += k ;
                    houseArea += sqrt(3)* k * k / 4.f;
                    break;
                case 'S':
                    if(horizontal)
                        b += k;
                    else
                        h += k ;
                    houseArea += k * k;
                    break;                   
            }
        }
        
        printf("%.4lf\n", (round(b/2) * round(h/2))- houseArea);
    }
    return 0;
}