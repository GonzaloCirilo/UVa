#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<double, double> ii;
typedef vector<ii> vii;

double distance(ii u , ii v){
    return sqrt(pow(u.first - v.first, 2) + pow(u.second - v.second, 2));
}

double bfclosest(vii p){
    double min = 999999999.0;
    for(int i = 0; i < p.size(); i++){
        for(int j = i + 1; j < p.size(); j++){
            if(distance(p[i], p[j]) < min)
                min = distance(p[i], p[j]);
        }
    }
    return min;
}

double minMidZone(vii p, double d){
    double min = d;
    sort(p.begin(), p.end(), [](const ii &a, const ii &b){
        return a.second < b.second;
    });

    for(int  i = 0; i < p.size(); i++){
        for(int j = i + 1; j < p.size() && (p[j].second - p[i].second) < min; ++j){
            if(distance(p[i], p[j]) < min)
                min = distance(p[i], p[j]);
        }
    }
    return min;
}

double closest(vii p){
    int n = p.size();
    if(n <= 3)
        return bfclosest(p);

    int mid = n / 2;
    auto midP = p[mid];

    double dl = closest(vii(p.begin(), p.begin() + mid));
    double dr = closest(vii(p.begin() + mid, p.end()));

    double dmin = min(dl, dr);

    vii midZone = vii();

    for(int i = 0; i < n; i++){
        if(abs(p[i].first - midP.first) < dmin){
            midZone.push_back(p[i]); 
        }
    }

    return min(dmin, minMidZone(midZone, dmin));

}

int main(){
    vii po = vii();
    int n; 
    double x, y;
    while(scanf("%d", &n) != EOF && n){
        double min = 99999999.0;
        for(int i = 0; i < n; i++){
            scanf("%lf %lf", &x, &y);
            po.push_back({x,y});
        }
        sort(po.begin(), po.end());

        double ans = closest(po);

        if(ans < 10000.0)
            printf("%.4lf\n", ans);
        else
            printf("INFINITY\n");
        po.clear();
    }
    return 0;
}