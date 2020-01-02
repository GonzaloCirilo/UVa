#include <stdio.h>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main(){
    int t, n;
    float x1, y1, x2, y2, transparency;
    scanf("%d", &t);
    int aux = 0;
    while(t--){
        if(aux != 0)
            printf("\n");
        aux ++;
        scanf("%d", &n);
        printf("%d\n", n * 2 + 1);
        vector<float> points;
        map<float, float> tPoints;
        while(n--){
            scanf("%f %f %f %f %f", &x1, &y1, &x2, &y2, &transparency);
            points.push_back(x1);
            points.push_back(x2);
            tPoints.insert({min(x1, x2), transparency});
            tPoints.insert({max(x1, x2), 1 / transparency});
        }
        sort(points.begin(), points.end());
        float light = 1.000;
        for(int i = 0; i < points.size(); i++){
            if(i == 0)
                printf("-inf ");
            else
                printf("%.3f ", points[i - 1]);
            
            printf("%.3f %.3f\n", points[i], round(light * 1000.0 ) / 1000.0);
            light *= tPoints.at(points[i]);               
        }
        printf("%.3f +inf %.3f\n", points[points.size() - 1], light);
    }
    return 0;
}