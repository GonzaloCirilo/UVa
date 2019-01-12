#include <stdio.h>
#include <string>
using namespace std;
int main(){
	int n, lenght = 0;
	char people[100][100];
	string song[5];
	song[0] = string("Happy");
	song[1] = string("birthday");
	song[2] = string("to");
	song[3] = string("you");
	song[4] = string("Rujia");
	scanf("%d\n", &n);
	for(int i = 0; i < n; i++)
		scanf("%s\n", &people[i]);
	while(lenght % 16 != 0 || lenght < n){
		int aux = lenght % n, songIndex;
		printf("%s: ", people[aux]);
		if(lenght % 16 == 11)
			songIndex = 4;
		else
			songIndex = lenght % 4;
		printf("%s\n", song[songIndex].c_str());
		lenght++;
	}
	return 0;
}