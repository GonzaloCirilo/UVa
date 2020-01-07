#include <stdio.h>
#include <map>
#include <vector>
using namespace std;

bool fastScan(int &x) {
	bool neg = false;
	int c = getchar();
	bool end = c == EOF;
	if (end)
		return false;
	x = 0;
	if (c == '-') {
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
	return true;
}

int main(){
    int t, a, b, c, u, v;
    fastScan(t);
    while(t--){
        map<int, int> sl;
        fastScan(a);
        fastScan(b);
        fastScan(c);
        vector<int> positions = vector<int>(a, 1);
        while(b--){
            fastScan(u);
            fastScan(v);
            sl.insert({u, v});
        }
        int player = 0;
        bool finished = false;
        while(c--){
            fastScan(u);
            if(!finished){
                positions[player] += u;
                if(sl.find(positions[player]) != sl.end()){
                    positions[player] = sl[positions[player]];
                }
                finished = finished || (positions[player] == 100);
            }            
            player = (player + 1) % a;
        }
        for(int i = 0; i < positions.size(); i++){
            printf("Position of player %d is %d.\n", i + 1, positions[i]);
        }

    }
    return 0;
}