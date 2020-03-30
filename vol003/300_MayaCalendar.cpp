#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    int n, dd, yyyy;
    string mm;
    map<string, int> haabMM;
    haabMM["pop"] = 0, haabMM["no"] = 1, haabMM["zip"] = 2, haabMM["zotz"] = 3;
    haabMM["tzec"] = 4, haabMM["xul"] = 5, haabMM["yoxkin"] = 6, haabMM["mol"] = 7;
    haabMM["chen"] = 8, haabMM["yax"] = 9, haabMM["zac"] = 10, haabMM["ceh"] = 11;
    haabMM["mac"] = 12; haabMM["kankin"] = 13, haabMM["muan"] = 14, haabMM["pax"] = 15;
    haabMM["koyab"] = 16, haabMM["cumhu"] = 17, haabMM["uayet"] = 18;


    string tzolkin[20] = {"imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac", "ahau"};
    scanf("%d", &n);
    printf("%d\n",n);
    while(n--){
        scanf("%d.", &dd);
        cin >> mm >> yyyy;

        long long days = dd + haabMM[mm] * 20 + yyyy * 365;

        yyyy = days / 260;
        dd = days % 13;
        int nameIndex = days % 20;

        cout << dd + 1 << " " << tzolkin[nameIndex] << " " << yyyy << endl;
    }
    return 0;
}