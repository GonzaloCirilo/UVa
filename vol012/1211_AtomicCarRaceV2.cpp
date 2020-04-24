#include <stdio.h>
#include <algorithm>
#include <limits.h>
#include <vector>
using namespace std;

vector<vector<double>> dp;

double getTime(double v, double e, double f, int r, int x){
    //printf("%lf %lf %lf %d %d\n", v, e, f, r, x);
    if(x >= r){
        return 1.0 / (v - e * (x - r));
    }else{
        return 1.0 / (v - f * (r - x));
    }
}

double getTotalTime(double v, double e, double f, int r, int x, int lc, int distance, double b){
    double sum = 0.0;
    for(int i = 0; i < x - distance; i++){
        sum += getTime(v,e,f,r,i);
    }
    sum += (lc) ? b : 0;
    return sum;
}
double b, v, e, f;
int n, a[103] = {}, r;

int main(){
    double dpp[102];
    while(scanf("%d", &n) && n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i + 1]);
            sum += a[i + 1];
        }
        scanf("%lf\n%d %lf %lf %lf", &b, &r, &v, &e, &f);

        for(int i = 1; i <= n; i++){
            dpp[i] = 999999999.0;
            for(int j = 0; j < i; j++){
                dpp[i] = min(dpp[i], dpp[j] + getTotalTime(v,e,f,r,a[i],j,a[j], b));
            }
        }

        printf("%.4lf\n", dpp[n]);

    }
    return 0;
}