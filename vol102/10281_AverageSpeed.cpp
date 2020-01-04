#include <stdio.h>
#include <string>

using namespace std;

long long timeInS(int h, int m, int s){
    return h * 3600 + m * 60 + s;
}

double toKMS(long long speed){
    return (double)speed / 3600;
}

int main(){
    char lines[100] = {};
    double speed = 0.0, distance = 0.0, elapsed = 0.0;
    int h, m, s;
    long long llSpeed;
    while(fgets(lines, 21, stdin)){
        string ss = string(lines);
        if(ss.length() >= 11){
            sscanf(ss.c_str(), "%d:%d:%d %lld", &h, &m, &s, &llSpeed);
            distance += speed * (timeInS(h,m,s) - elapsed);
            elapsed = timeInS(h,m,s);
            speed = toKMS(llSpeed);
        }else{
           if (ss[ss.length()-1] == '\n') {
                ss.erase(ss.length()-1);
            }
            sscanf(ss.c_str(), "%d:%d:%d", &h, &m, &s);
            distance += speed * (timeInS(h,m,s) - elapsed);
            elapsed = timeInS(h,m,s);
            printf("%s %.2f km\n", ss.c_str(), distance);
        }
    }
    return 0;
}