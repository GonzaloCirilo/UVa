#include <stdio.h>
#include <map>
#include <iostream>
#include <string>
using namespace std;
int main() {
	map<string, char>dict;
	dict[".-"] = 'A';
	dict["-..."] = 'B';
	dict["-.-."] = 'C';
	dict["-.."] = 'D';
	dict["."] = 'E';
	dict["..-."] = 'F';
	dict["--."] = 'G';
	dict["...."] = 'H';
	dict[".."] = 'I';
	dict[".---"] = 'J';
	dict["-.-"] = 'K';
	dict[".-.."] = 'L';
	dict["--"] = 'M';
	dict["-."] = 'N';
	dict["---"] = 'O';
	dict[".--."] = 'P';
	dict["--.-"] = 'Q';
	dict[".-."] = 'R';
	dict["..."] = 'S';
	dict["-"] = 'T';
	dict["..-"] = 'U';
	dict["...-"] = 'V';
	dict[".--"] = 'W';
	dict["-..-"] = 'X';
	dict["-.--"] = 'Y';
	dict["--.."] = 'Z';
	dict["-----"] = '0';
	dict[".----"] = '1';
	dict["..---"] = '2';
	dict["...--"] = '3';
	dict["....-"] = '4';
	dict["....."] = '5';
	dict["-...."] = '6';
	dict["--..."] = '7';
	dict["---.."] = '8';
	dict["----."] = '9';
	dict[".-.-.-"] = '.';
	dict["--..--"] = ',';
	dict["..--.."] = '?';
	dict[".----."] = '\'';
	dict["-.-.--"] = '!';
	dict["-..-."] = '/';
	dict["-.--."] = '(';
	dict["-.--.-"] = ')';
	dict[".-..."] = '&';
	dict["---..."] = ':';
	dict["-.-.-."] = ';';
	dict["-...-"] = '=';
	dict[".-.-."] = '+';
	dict["-....-"] = '-';
	dict["..--.-"] = '_';
	dict[".-..-."] = '"';
	dict[".--.-."] = '@';
	int t;
	cin >> t;
	char c, prev = '\'';
	cin.ignore(100, '\n');
	for (int i = 0; i < t; i++) {
		if (i)
			printf("\n");
		string s, str;
		printf("Message #%d\n", i + 1);
		getline(cin, str);
		int l = str.length(), cont = 0;
		while (cont < l) {
			c = str[cont];
			if (c != ' ')
				s += c;
			else if (c == ' ' && !s.empty()) {
				printf("%c", dict[s]);
				s.clear();
			}
			else if (c == ' ' && s.empty() && prev == ' ') {
				printf(" ");
				c = ',';
			}
			prev = c;
			cont++;
		}
		if (!s.empty())
			printf("%c", dict[s]);
			
		printf("\n");
	}
	return 0;
}