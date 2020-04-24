#include <stdio.h>
#include <algorithm>
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

double getTotalTime(double v, double e, double f, int r, int x, int lc, int distance){
    double sum = 0.0;
    for(int i = distance; i < x; i++){
        sum += getTime(v,e,f,r,i - lc);
    }
    return sum;
}
double b, v, e, f;
int n, a[101] = {}, r;

double rec(int nn, int lc, int distance){
    if(nn == n) return 0.0;
    if(dp[nn][lc] != 999999999.0) return dp[nn][lc];
    double t = getTotalTime(v,e,f,r,a[nn],lc, distance);
    //printf("== nn:%d lc:%d a[i]:%d dis:%d %lf\n", nn, lc, a[nn], distance, t);
    return dp[nn][lc] = min(rec(nn + 1, a[nn], a[nn]) + t + b, rec(nn + 1, lc, a[nn]) + t);

}

int main(){

    while(scanf("%d", &n) && n){
        int sum = 0;
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
            sum += a[i];
        }
        dp = vector<vector<double>>(n, vector<double>(sum + 1, 999999999.0));
        scanf("%lf\n%d %lf %lf %lf", &b, &r, &v, &e, &f);

        printf("%.4lf\n", rec(0, 0, 0));
    }
    return 0;
}