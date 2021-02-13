#include <iostream>

using namespace std;

int main() {
    int c, n, k, p;
    cin >> c;

    for(int i = 1; i <= c; i++){
        cin >> n >> k >> p;
        int ans = (k + p) % n;
        cout << "Case " << i << ": " << (ans? ans : n) << endl;
    }

    return 0;
}