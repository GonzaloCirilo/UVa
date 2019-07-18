#include <stdio.h>
#include <string>
using namespace std;
int main(){
    int n, p, cont = 0;
    char token[82];
    while(scanf("%d %d\n", &n, &p) && (n || p)){
        if(cont)
            printf("\n");
        for(int i = 0; i < n; i++){
            fgets(token,82,stdin);
        }
        double price = 0, minp = 99999999999;
        double nele = 0, maxn = 0;
        string ans;
        for(int i = 0; i < p; i++){
            fgets(token, 82, stdin);
            scanf("%lf %lf\n", &price, &nele);
            double compliance = nele / n;
            if(compliance > maxn){
                minp = price;
                maxn = compliance;
                ans = string(token);
            }
            if(compliance == maxn && price < minp){
                minp = price;
                ans = string(token);
            }
            for(int i = 0; i < nele; i++){
                fgets(token,82,stdin);
            }
        }
        printf("RFP #%d\n", (cont++) + 1);
        printf("%s", ans.c_str());
    }
    return 0;
}