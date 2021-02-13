#include <stdio.h>

int main(){
    int p[3], sum;
    while(scanf("%d %d %d", &p[0], &p[1], &p[2]) != EOF){
        sum = p[0] + p[1] + p[2];
        switch (sum) {
        case 1:
            for(int i = 0; i < 3; i++){
                if(p[i] == 1){
                    printf("%c\n", 'A' + i);
                    break;
                }
            }
            break;
        case 2:
            for(int i = 0; i < 3; i++){
                if(p[i] == 0){
                    printf("%c\n", 'A' + i);
                    break;
                }
            }
            break;
        default:
            printf("*\n");
            break;
        }
    }
    return 0;
}