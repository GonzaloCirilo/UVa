#include <stdio.h>
#include <string>
#include <map>
#include <iostream>
#include <math.h>
using namespace std;
map<string, pair<string, string> >person;
map < string, int>genes;
string findgene(string s) {
	if (person[s].second == "") return person[s].first;
	string gp1 = findgene(person[s].first), gp2 = findgene(person[s].second), r;
	if (gp1==gp2) {
		r = gp1;
	}
	else if (abs(genes[gp1] - genes[gp2]) == 1) {
		if (genes[gp1] == 0)
			r = gp2;
		else
			r = gp1;
	}
	else {
		r = "recessive";
	}
	person[s] = { r,"" };
	return r;
}
int main() {
	int n;
	string s1, s2;
	char c1[21], c2[21];
	scanf("%d", &n);
	map<int, string>ngenes;
	genes["non-existent"] = -1; genes["recessive"] = 0; genes["dominant"] = 1;
	ngenes[1] = "non-existent"; ngenes[-1] = "recessive"; ngenes[0] = "dominant";
	for (int i = 0; i < n; i++) {
		scanf("%20s %20s", &c1, &c2);
		s1 = string(c1); s2 = string(c2);
		if (s2 == "non-existent" || s2 == "recessive" || s2 == "dominant") {
			person[s1] = { s2,"" };
		}
		else {
			if (person.find(s2) != person.end())
				person[s2].second = s1;
			else
				person[s2] = { s1," " };
		}
	}
	for (pair<string, pair<string, string> > x : person) {
		findgene(x.first);
	}
	for (pair<string,pair<string,string> > x : person) {
		cout << x.first << " " << x.second.first << endl;
	}
	return 0;
}
