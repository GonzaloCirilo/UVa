#include <stdio.h>
#include <string>
#include <regex>
using namespace std;
string trim(string s){
    int sBegin = s.find_first_not_of(" ");
    return s.substr(sBegin, s.length());
}
int main(){
	char stringy[1001];
	while(fgets(stringy,1001,stdin) && stringy[0] != '*'){
		stringy[strlen(stringy)-1] = '\0';
		string s = trim(string(stringy));
		if (regex_match (s, regex("[-+]?\\d+(\\.\\d+([eE][-+]?\\d+)?|[eE][-+]?\\d+)") ))
	    	printf("%s is legal.\n", s.c_str());
	    else
	    	printf("%s is illegal.\n", s.c_str());
	}
	return 0;
}