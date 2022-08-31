#include <iostream>
#include <math.h>

using namespace std;

double logWithBase(long long base, long long n){
    //cout << (log(n)/ log(base))<< "?????" << endl;
    return (log(n)/ log(base));
}

// Proof: 125+25*6+5*36+216
// (5^3)*(6^0)+(5^2)*(6^1)+ (5^1)*(6^2)+(6^3) *(5^0)
int main(){
    long long h, nWorker;
    while(true){
        cin >> h >> nWorker;
        if(h == 0 && nWorker == 0) break;
        int n = -1, ex = -1;
        for(int i = 0; i < 1000; i++){
            auto current = logWithBase(i, nWorker);
            if(abs(current - logWithBase(i+1, h)) < 0.0000001){
                //cout << "current: " << current << endl;
                n = i, ex = round(current);
                break;
            }
        }
        if(nWorker == 1 && h % 2 == 0) {
            n = 1, ex = (int)logWithBase(2, h);
        }
        //cout << n << "==="<<ex<< endl;
        if(n == -1 && ex == -1){
            cout << 1 << " " << h + nWorker << endl;
            continue;
        }

        long long lazy = 0, hStack = 0;
        for(int i = 0; i < ex; i++){
            lazy += (long long)(pow(n, i));
            hStack += (long long)(pow(n, i)) * (long long)(pow(n+1, ex-i));
        }
        hStack += nWorker;
        cout << lazy << " " << hStack << endl;
    }
    return 0;
}