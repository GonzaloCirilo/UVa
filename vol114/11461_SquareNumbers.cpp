#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a, b;
    vector<int> squaredNums = vector<int>();
    for (int i = 1; i * i <= 100000; i++) {
      squaredNums.push_back(i * i);
    }
    vector<int> prefix = vector<int>(100002, 0);
    int sqCounter = 0;
    for (int i = 1; i <= 100000; i++) {
        prefix[i] = prefix[i-1];
        if (squaredNums[sqCounter] == i) {
            sqCounter++;
            prefix[i]++;
        }
    }
    while(cin >> a >> b) {
        if (a == 0 && b == 0) break;
        cout << prefix[b] - prefix[a-1] << endl;
    }

}
