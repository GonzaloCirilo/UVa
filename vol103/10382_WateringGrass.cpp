#include <stdio.h>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
struct Comparator{
	bool operator()(pair<double, double> const &a, pair<double, double> const &b){
		if (a.first != b.first){
			return a.first < b.first;
		}
		return a.second > b.second;
	}
};

double apothem(double r, double w){
	return sqrt(r * r - w * w / 4);
}
int main(){
	int n;
	double l, w, pos, r;
	while (scanf("%d %lf %lf", &n, &l, &w) != EOF){

		vector<pair<double, double>> v;
		for (int i = 0; i < n; i++){
			scanf("%lf %lf", &pos, &r);
			auto dx = apothem(r, w);
			if (r * r >= w * w / 4)
				v.push_back({max(0.0, pos - dx), min(l, pos + dx)});
		}
		Comparator comp;
		sort(v.begin(), v.end(), comp);

		int ans = 0;
		double right = 0.0;

		for (int i = 0; i < v.size(); i++){

			for (int j = i; j < v.size(); j++){
				if (v[j].first > right)
					break;
				if (v[j].second > v[i].second)
					i = j;
			}

			if (v[i].first > right || v[i].second < right)
				break;

			right = v[i].second;
			ans++;
			if (right == l)
				break;
		}
		if (right >= l)
			printf("%d\n", ans);
		else
			printf("-1\n");
	}
	return 0;
}
