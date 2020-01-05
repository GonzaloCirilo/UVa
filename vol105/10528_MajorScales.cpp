#include <stdio.h>
#include <set>
#include <ctype.h>
using namespace std;

int main() {
	// the notes with # will be represented with a lowercase
	char chromaticNotes[12] = { 'C', 'c', 'D', 'd', 'E', 'F', 'f', 'G', 'g', 'A', 'a', 'B' };
	int major[7] = { 2,2,1,2,2,2,1 };
	bool finish = false;
	while (true) {
		char c = (char) 0, prev;
		set<char> notes, aux;
		while (true) {
			c = getchar();
			if (c == '\n') { 
				if(prev != (char)0)
					notes.insert(prev);
				break;
			}
			if (c == 'N' && prev == 'E') {
				finish = true;
				break;
			}
			if (c == ' ') {
				notes.insert(prev);
				prev = (char)0;
			}
			else if (c == '#') {
				prev = tolower(prev);
			}
			else {
				prev = c;
			}
		}

		if (finish) break;

		int cont = 0;

		for (int i = 0; i < 12; i++) {
			int index = i; aux = notes;
			for (int j = 0; j < 8; j++) {
				aux.erase(chromaticNotes[index]);
				if (j == 7) break;
				index = (index + major[j]) % 12;
			}
			if (aux.empty()) {
				if (cont != 0)
					putchar(' ');
				cont++;
				if (islower(chromaticNotes[i])) {
					putchar(toupper(chromaticNotes[i]));
					putchar('#');
				}else
					putchar(chromaticNotes[i]);
			}
		}
		putchar('\n');
	}

	return 0;
}