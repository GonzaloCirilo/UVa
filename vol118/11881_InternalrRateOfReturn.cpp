#include <stdio.h>
#include <math.h>
#include <vector>

using namespace std;

typedef vector<double> vd;

double NPV(vd cashflow, double irr){
    double npv = cashflow[0];

    for(int i = 1; i < cashflow.size(); i++){
        npv += ((double) cashflow[i]) / pow(1 + irr, i);
    }
    return npv;
}

vd cashflow;
double IRR(double l, double r){
    double mid = (l + r) / 2;

    double tNPV = NPV(cashflow, mid);

    //printf("===%lf %lf %lf %lf\n", l, r, mid, tNPV);

    if((int)(tNPV * 100000) == 0){
        return mid;
    }

    if(tNPV < 0){
        return IRR(l, mid);
    }else{
        return IRR(mid, r);
    }

}

int main(){
    int t, ci;
    while(scanf("%d", &t) != EOF && t){
        cashflow = vd();
        for(int i = 0; i <= t; i++){
            scanf("%d", &ci);
            cashflow.push_back((double)ci);
        }
        printf("%.2lf\n", IRR(-0.99, 128.0));
    }
    return 0;
}