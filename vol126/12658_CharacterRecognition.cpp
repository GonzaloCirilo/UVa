#include <iostream>
#include <string>
using namespace std;
int main(){
    int n;
    cin >> n;
    string s;
    for(int i = 0; i < 5; i++){
        cin >> s;
        if(i == 3) {
            for(int i = 0; i < n; i++) {
                auto token = s.substr(i*4, 3);
                if(token == ".*."){
                    cout << 1;
                } else if(token == "*..") {
                    cout << 2;
                } else if(token == "..*"){
                    cout << 3;
                }
            }
        }
    }
    cout << endl;
    return 0;
}