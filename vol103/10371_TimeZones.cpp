#include <iostream>
#include <string>
#include <map>
#include <math.h>

using namespace std;

int main(){

    map<string, double> tz;
    tz["UTC"] = 0, tz["GMT"] = 0, tz["BST"] = 1, tz["IST"] = 1, tz["WET"] = 0;
    tz["WEST"] = 1, tz["CET"] = 1, tz["CEST"] = 2, tz["EET"] = 2, tz["EEST"] = 3;
    tz["MSK"] = 3, tz["MSD"] = 4, tz["AST"] = -4, tz["ADT"] = -3, tz["NST"] = -3.5;
    tz["NDT"] = -2.5, tz["EST"] = -5, tz["EDT"] = -4, tz["CST"] = -6, tz["CDT"] = -5;
    tz["MST"] = -7, tz["MDT"] = -6, tz["PST"] = -8, tz["PDT"] = -7, tz["HST"] = -10;
    tz["AKST"] = -9, tz["AKDT"] = -8, tz["AEST"] = 10, tz["AEDT"] = 11, tz["ACST"] = 9.5;
    tz["ACDT"] = 10.5, tz["AWST"] = 8;

    int t;
    cin >> t;

    string time, m, u, v;
    int itime[7]= {};
    for(int i = 0; i < t; i++){
        cin >>time;
        int h, min;
        if(time[0] == 'n' || time[0] == 'm'){
            cin >> u >> v;
            min = 0;
            if(time[0] == 'n')
                h = 12;
            else
                h = 0;

        }else{
            for(int j = 0; j < time.size(); j++){
                itime[j] = time[j] - '0';
            }
            cin >> m >> u >> v;
            if(time[1] == ':'){
                h = itime[0];
                h += (m[0] == 'p' && h != 12) * 12;
                min = itime[2] * 10 + itime[3];
            }else{
                h = itime[0] * 10 + itime[1];
                h += (m[0] == 'p' && h != 12) * 12;
                if(h == 12 && m[0] == 'a') h = 0;
                min = itime[3] * 10 + itime[4];
            }
            
        }
        
        double dif = tz[v] - tz[u];
        //printf("%d:%02d dif: %lf = ", h, min, dif);

        if(abs(dif) - (int)abs(dif) > 0){
            min += 30 * dif / abs(dif);
            if(min >= 60){
                min = min - 60;
                h++;
            }else if(min < 0){
                min = 60 + min;
                h--;
            }
            h = (h + 24 + (int)dif) % 24;
        }else{
            h = (h + 24 + (int)dif) % 24;
        }

        if(h == 0 && min == 0){
            printf("midnight\n");
        }else if(h == 12 && min == 0){
            printf("noon\n");
        }else{
            if(h >= 12){
                h -= 12;
                printf("%d:%02d p.m.\n", h? h : 12, min);
            }else{
                printf("%d:%02d a.m.\n", h? h : 12, min);
            }
        }

    }
    return 0;
}