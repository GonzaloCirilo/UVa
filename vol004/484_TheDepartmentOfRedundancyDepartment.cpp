#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int x;
    unordered_map<int, int> m;
    vector<int> s;
    while (cin >> x) {
        if (m.insert(pair<int, int>(x, 1)).second) {
            s.push_back(x);
        } else {
            m[x]++;
        }
    }
    for (auto it = s.begin(); it != s.end(); it++) {
        cout << (*it) << " " << m[(*it)] << endl;
    }

    return 0;
}