#include <stdio.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;

double minToDegree(int m) {
    return m / 60.0;
}

int main() {
    string t;
    double s, a;
    while (cin >> s >> a >> t) {
        if (t[0] == 'm') {
            a = minToDegree(a);
            //printf("converted to: %lf\n", angle);
        }
        while (a > 360) {
            a -= 360;
        }
        
        if (a > 180) {
            a = (360 - a);
        }

        double r = (6440.0 + s);

        double arcDistance = 2 * a * (M_PI / 360) * r;
        double chordDistance = 2 * r * sin(a * M_PI / 180/2);

        printf("%.6f %.6f\n", arcDistance, chordDistance);
    }
    
    return 0;
}