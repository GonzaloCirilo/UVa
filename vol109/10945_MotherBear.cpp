#include <stdio.h>
#include <string>
#include <algorithm>
using namespace std;
int dp[2006][2006];
bool isPalindrome(string st) {//Iterative
	int lenght = st.size();
	for (int i = lenght - 2; i >= 0; i--) {
		for (int j = i + 1; j < lenght; j++) {
			if (st[i] == st[j])
				dp[i][j] = dp[i + 1][j - 1];
			else
				dp[i][j] = 1 + min(dp[i + 1][j], dp[i][j - 1]);
		}
	}
	return dp[0][lenght - 1] == 0;
}
int main(){
    while(true){
        string s, o;
        char token;
        token = getchar();
        while(token != '\n' && token != EOF){
            o.push_back(token);
            if(token - 'A' >= 0 && token - 'A' <= 26)
                s.push_back(tolower(token));
            else if(token - 'a' >= 0 && token - 'a' <= 26)
                s.push_back(token);
            token = getchar();
            
        }
        //printf("%s\n", o.c_str());
        if(o == "DONE\n" || o == "DONE")
            break;
        if(isPalindrome(s))
            printf("You won't be eaten!\n");
        else
            printf("Uh oh..\n");
    }
}