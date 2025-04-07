#include <iostream>
#include <string>
#include <set>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != -1) {
        cout << "Round " << n << endl;
        string target, currentState;
        cin >> target;
        set<char> tWords, cWords, misses;
        for (int i = 0; i < target.size(); i++) {
            tWords.insert(target[i]);
            //cout << target[i] << endl;
        }
        cin >> currentState;
        bool lost = false, won = false;
        for (int i = 0; i < currentState.size(); i++) {
            if (tWords.find(currentState[i]) == tWords.end()) {
                misses.insert(currentState[i]);
            } else {
                cWords.insert(currentState[i]);
            }
            //cout << "Misses: " << misses.size() << " Hit: " << cWords.size() << endl;
            if (tWords.size() == cWords.size()) {
                cout << "You win." << endl;
                won = true;
                break;
            } else if (misses.size() == 7) {
                cout << "You lose." << endl;
                lost = true;
                break;
            }
        }
        if (!won && !lost) {
            cout << "You chickened out." << endl;
        }
    }
    return 0;
}