#include <iostream>
#include <string>
using namespace std;

int main() {
    string line;
    while(cin >> line){
        if(line == "0") break;
        int sum = 0, factor = -1;
        for(int i = 0; i < line.size(); i++){
            sum += factor * (line[i] - '0');
            factor *= -1;
        }
        cout << line;
        if(sum % 11 == 0){
            cout << " is a multiple of 11." << endl;
        } else {
            cout << " is not a multiple of 11." << endl;
        }
    }
    return 0;
}