// oeis A003056
#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int t;
    unsigned long long n;
    cin >> t;
    while(t--){
        cin >> n;
        cout << (unsigned long long)floor((sqrt(1 + 8 * n) - 1)/ 2) << endl;
    }
    return 0;
}