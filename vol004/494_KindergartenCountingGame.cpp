#include <stdio.h>
#include <string.h>
#include <string>
#include <algorithm>
using namespace std;
int main(){
	char stringy [9999];
	while(fgets(stringy, 9999, stdin)){
		string s = string(stringy);
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		int lenght = strlen(stringy), ans = s[0] - 'a' <=27 && s[0] - 'a'>= 0? 1 : 0;
		for(int i=1;i<lenght;i++){
			if(s[i] - 'a' <=27 && s[i] - 'a' >= 0 && (s[i-1] - 'a' < 0 || s[i-1] - 'a' > 27) ){
				ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}