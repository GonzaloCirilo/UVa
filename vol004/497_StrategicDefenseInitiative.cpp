#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
using namespace std;
int main()
{
	vector<int> input, a, links, ans;
	int t;
	scanf("%d", &t);
	string s;
	cin.ignore();
	cin.ignore();
	while (t--)	{
		input.clear();
		string s;
		while (getline(cin, s) && s != ""){
			input.push_back(atoi(s.c_str()));
		}
		int n = input.size();
		a = vector<int>(n, 1);
		links = vector<int>(n, -1);
		a[0] = 1;
		for (int i = 1; i < n; ++i) {
			for (int j = 0; j < i; ++j){
				int l = 0;
				if (input[j] < input[i])
					l = a[j] + 1;
				if (l > a[i]) {
					a[i] = l;
					links[i] = j;
				}
			}
		}
		int r = 0, max = -1;
		for (int j = 0; j < a.size(); j++) {
			if (max < a[j]) {
				max = a[j];
				r = j;
			}
		}
		ans = vector<int>(1, input[r]);
		while (links[r] != -1){
			r = links[r];
			ans.push_back(input[r]);
		}
		cout << "Max hits: " << ans.size() << endl;
		for (int i = ans.size() - 1; i >= 0; i--) {
			printf("%d\n", ans[i]);
		}
		if (t)
			printf("\n");
	}
	return 0;
}
