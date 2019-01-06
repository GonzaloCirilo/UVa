#include <stdio.h>
#include <map>
using namespace std;
int main(){
	map<string,string> dict;
	dict.insert({"HELLO\n","ENGLISH"});
	dict.insert({"HOLA\n","SPANISH"});
	dict.insert({"HALLO\n","GERMAN"});
	dict.insert({"BONJOUR\n","FRENCH"});
	dict.insert({"CIAO\n","ITALIAN"});
	dict.insert({"ZDRAVSTVUJTE\n","RUSSIAN"});
	char token[20];
	int cont = 1;
	while(fgets(token,20,stdin) && token[0] != '#'){
		printf("Case %d: ", cont++);
		if(dict.find(string(token)) != dict.end())
			printf("%s\n", dict[string(token)].c_str());
		else
			printf("UNKNOWN\n");
	}
	return 0;
}