#include <stdio.h>

int main(){
    int s, aux;
    scanf("%d", &s);
    for(int i = 1; i <= s; i++){
        int in = 13; bool ans = true;
        while(in--){
            scanf("%d", &aux);
            ans = ans && aux;
        }
        printf("Set #%d: ", i);
        if(ans)
            printf("Yes\n");
        else 
            printf("No\n");
    }
    return 0;
}