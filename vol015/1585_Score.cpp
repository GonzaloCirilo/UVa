#include <stdio.h>
int main(){
    int t;
    char c;
    scanf("%d\n", &t);
    while(t--){
        int ans = 0, aux = 0;
        while((c=getchar()) != '\n'){
            if(c == 'O')
                ans += ++aux;
            else
                aux = 0;
        }
        printf("%d\n", ans);
    }
    
    return 0;
}