#include <stdio.h>
int main(){
    long long special[21] = {1, 64, 729, 4096, 15625, 46656, 117649, 262144, 531441,1000000, 1771561, 2985984, 4826809, 7529536, 11390625, 16777216, 24137569, 34012224,47045881, 64000000, 85766121}, aux;
    while (scanf("%lld", &aux) != EOF && aux){
        bool isSpecial = false;
        for(int i = 0; i < 21; i++){
            isSpecial = aux == special[i];
            if(isSpecial) break;
        }
        if(isSpecial)
            printf("Special\n");
        else
            printf("Ordinary\n");
    }
    
}