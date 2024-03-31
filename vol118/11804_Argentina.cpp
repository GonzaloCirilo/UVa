#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Player
{
    string name;
    int atk, def;

    bool operator<(const Player& op) const {
        if (atk == op.atk && def == op.def) {
            return lexicographical_compare(name.begin(), name.end(), op.name.begin(), op.name.end());
        } else if (atk == op.atk) {
            return def < op.def;
        } else {
            return atk > op.atk;
        }
    }

};

void printPlayers(vector<Player> players) {
    vector<string> ss;
    for (int i = 0; i < players.size(); i++) {
        ss.push_back(players[i].name);
    }
    cout << "(";
    // sort lexicographically
    sort(ss.begin(), ss.end());
    for (int i = 0; i < ss.size(); i++) {
        if (i > 0)
            cout << ", ";

        cout << ss[i];
    }
    cout << ")" << endl;
}


int main() {
    int t, a, d, c = 1;
    string n;
    cin >> t;
    while (t--) {
        vector<Player> arr = vector<Player>();
        cout << "Case " << c++ << ":" << endl;
        for(int i = 0; i < 10; i++) {
            cin >> n >> a >> d;
            arr.push_back(Player{n, a, d});
        }
        sort(arr.begin(), arr.end());
        //for(int i = 0; i < 10; i++) {
            //cout << "p: " << arr[i].name << " atk: " << arr[i].atk << " def: " << arr[i].def << endl;
        //}
        printPlayers({arr.begin(), arr.begin() + 5});
        printPlayers({arr.begin()+5, arr.end()});
    }
    return 0;
}