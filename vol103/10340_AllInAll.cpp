#include <stdio.h>
#include <queue>
using namespace std;
int main() {
	queue<char> subsequence;
	char token;
	while(scanf("%c", &token) != EOF){
		subsequence.push(token);
		while(scanf("%c", &token) && token != ' '){
			subsequence.push(token);
		}
		while(scanf("%c", &token) && token != '\n'){
			if(subsequence.front() == token)
				subsequence.pop();
		}
		if(!subsequence.empty())
			printf("No\n");
		else
			printf("Yes\n");
		subsequence = queue<char>();
	}
	return 0;
}