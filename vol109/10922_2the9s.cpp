#include <iostream>
#include <string>
using namespace std;
int main(){
    string s;
    while(getline(cin, s) && s != "0") {
        int sum = 0, d = 1;
        for(int i = 0; i < s.size(); i++){
            sum += s[i] - '0';
        }

        while(sum > 10){
            int aux = sum;
            sum = 0;
            while(aux){
                sum += aux % 10;
                aux /= 10;
            }
            d++;
        }
        cout << s;
        if(sum == 9) {
            cout << " is a multiple of 9 and has 9-degree " << d << "." << endl;
        } else {
            cout << " is not a multiple of 9." << endl;
        }
        
    }
    return 0;
}