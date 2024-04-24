#include <stdio.h>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

void fastScan(int &x){
    bool neg = false;
	int c;
	x = 0;
	c = getchar();
	if (c == '-')
	{
		neg = true;
		c = getchar();
	}
	for (; (c > 47 && c < 58); c = getchar())
		x = (x << 1) + (x << 3) + c - 48;
	if (neg)
		x *= -1;
}

int main () {
    int t, n, x;
    fastScan(t);
    while (t--) {
        fastScan(n);
        int maxe = 0, anchor = 1, i = 1, naux = n;
        bool repeated = false;
        vector<int> arr;
        map<int, int> mm;
        while (n--) {
            fastScan(x);
            arr.push_back(x);
            bool rep = false;
            if (mm.find(x) != mm.end() && mm[x] >= anchor) {
                rep = true;
            }
            if (rep) {
                //printf("from %d to %d\n", anchor, i);
                maxe = max(maxe, i - anchor);
                anchor = mm[x] + 1;
            }
            mm[x] = i;
            i++;
        }
        //printf("ends from %d to %d\n", anchor, i);
        maxe = max(maxe, i - anchor);
        

        printf("%d\n", maxe);
    }
    return 0;
}