#include <stdio.h>
#include <map>
using namespace std;
int main() {
	int t, n, table[26] = { 2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,-1,7,7,8,8,8,9,9,9,-1 }, dupe, lenght;
	char rune;
	map<string, int>dir;
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		dir.clear();
		if (i)
			printf("\n");
		scanf("%d\n", &n);
		while (n--) {
			lenght = 0; char phone[10] = {};
			while (scanf("%c", &rune) != EOF && rune != '\n') {
				if (rune != '-' && rune != ' ') {
					if (rune - 'A' < 0) {
						phone[lenght] = rune;
					}
					else {
						int index = rune - 'A';
						phone[lenght] = (char)(table[index] + '0');
					}
					lenght++;
					if (lenght == 3) {
						phone[lenght] = '-';
						lenght++;
					}

				}
			}
			if (!dir.insert({ string(phone),1 }).second)
				dir[string(phone)]++;
		}
		dupe = 0;
		for (auto it = dir.begin(); it != dir.end(); it++) {
			if ((*it).second > 1) {
				printf("%s %d\n", (*it).first.c_str(), (*it).second);
				dupe++;
			}
		}
		if (!dupe)
			printf("No duplicates.\n");
	}
	return 0;
}