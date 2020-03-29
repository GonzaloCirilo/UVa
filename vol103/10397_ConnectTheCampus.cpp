#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>
using namespace std;
typedef pair<int, int> ii;
typedef pair<double, ii> fii;

vector<int> pset;

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

void init(int n){
    pset = vector<int>(n, -1);
}

int findset(int p){
    if(pset[p] == -1)
        return p;
    return pset[p] = findset(pset[p]);
}

bool isSameSet(int a, int b){
    return findset(a) == findset(b);
}

bool unionSet(int a, int b){
    if(!isSameSet(a, b)){
        pset[findset(a)] = findset(b);
        return true;
    }
    return false;
}

double distanceEU(int x1, int y1, int x2, int y2) {
	return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

int main(){
    int n, m, xs[753] = {}, ys[753] = {}, u, v;
    while(scanf("%d", &n) != EOF){
        init(n);
        for(int i = 0; i < n; i++){
            scanf("%d %d", &xs[i], &ys[i]);
        }
        int edges = 0;
        scanf("%d", &m);
        for(int i = 0; i < m; i++){
            scanf("%d %d", &u, &v);
            if(unionSet(u - 1, v - 1)) edges++;
        }

        priority_queue<fii, vector<fii>, greater<fii>> pq;

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                pq.push({distanceEU(xs[i], ys[i], xs[j], ys[j]), {i,j}});
            }
        }

        double ans = 0.0;
        while(edges != n - 1 && !pq.empty()){
            fii z = pq.top(); pq.pop();
            if(unionSet(z.second.first, z.second.second)){
                ans += z.first;
                edges++;
            }
        }
        printf("%.2lf\n", ans);
    }
    return 0;
}