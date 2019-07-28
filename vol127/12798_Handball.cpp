#include <stdio.h>
int main(){
    int n, m, aux, ans;
    while(scanf("%d %d", &n, &m) != EOF){
        ans = 0;
        for(int i = 0; i < n; i++){
        	int cont = 0;
            for(int j = 0; j < m; j++){
                scanf("%d", &aux);
                cont += (bool)(aux);
            }
            if(cont == m)
                ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}