#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
using namespace std;
int main() {
	char title[85], author[85];
	map<string, string>shelf, sorted, returned;
	string line;
	while (getline(cin, line) && line != "END") {
		sscanf(line.c_str(), "\"%[^\"]\" by %[^\n\r]", title, author);
		shelf.insert({ string(author) + " " + string(title),string(title) });
		sorted.insert({ string(title),string(author) });
	}
	//scanf("%s\n", &title);
	//getchar();
	char cmd[15];
	while (getline(cin, line) && line != "END") {
		sscanf(line.c_str(), "%s \"%[^\"]\"", cmd, title);
		if (cmd[0] == 'B')
			shelf.erase(sorted[title]+ " " + title);
		else if (cmd[0] == 'R')
			returned.insert({ sorted[title] + " " + title,title });
		else if (cmd[0] == 'S') {
			for (auto it = returned.begin(); it != returned.end(); it++) {
				shelf.insert({ (*it).first,(*it).second });
				auto prevIt = shelf.find((*it).first);
				if (prevIt == shelf.begin() || prev(prevIt) == shelf.end())
					printf("Put \"%s\" first\n", (*prevIt).second.c_str());
				else {
					printf("Put \"%s\"", (*prevIt).second.c_str());
					prevIt = prev(prevIt);
					printf(" after \"%s\"\n", (*prevIt).second.c_str());
				}
			}
			printf("END\n");
			returned.clear();
		}
	}
	return 0;
}