#include <stdio.h>
#include <vector>
using namespace std;
int main() {
	int months, dRecords;
	double down, loan, per;
	vector<double> dep;
	while (scanf("%d %lf %lf %d", &months, &down, &loan, &dRecords) && months > 0) {
		dep = vector<double>(101);
		for (int i = 0; i < dRecords; i++) {
			int aux;
			scanf("%d %lf", &aux, &per);
			dep[aux] = per;
		}
		for (int i = 0; i < 101; i++) {
			if (dep[i])
				per = dep[i];
			else 
				dep[i] = per;
		}
		double owns = loan, worth = (loan + down)*(1.0 - dep[0]);
		int ans = 0;
		while (owns > worth) {
			ans++;
			owns -= (loan/months);
			worth -= (dep[ans] * worth);
		}
		if (ans != 1)
			printf("%d months\n", ans);
		else
			printf("1 month\n");
	}
	return 0;
}