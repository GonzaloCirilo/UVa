#include <stdio.h>
#include <vector>
#include <sstream>
#include <string>
#include <iostream>
using namespace std;
int main(){
    char names[21][82] = {};
    int t, n;
    scanf("%d", &t);
    while(t--){
        bool invalid[21] = {};
        scanf("%d\n", &n);
        for(int i = 0; i < n; i++){
            fgets(names[i], 82, stdin);
        }
        char token[100];
        int votes[1001][21] = {}, i = 0;
        while(fgets(token, 100, stdin) != NULL && token[0] != '\n'){
            int j = 0, v;
            string s(token);
            stringstream ss(s);
            while(ss >> v) {
                votes[i][j++] = v - 1;
            }
            i++;
        }

        double highestVote = 0.0;
        vector<int> winners = vector<int>();
        int auxn = n;

        while(highestVote < 0.50){//winners array is equal to the current number of valid candidate or more than 50% of votes
            winners.clear();
            int count[21] = {};
            for(int j = 0; j < i; j++){
                int k = 0;
                while(invalid[votes[j][k]]){
                    k++;
                }
                count[votes[j][k]]++;
            }
            double hv = 0.0;
            int min = 1003;

            for(int j = 0; j < n; j++){
                if((double)count[j] / i > hv){
                    hv = (double)count[j] / i;
                }
                if(min > count[j] && !invalid[j]){
                    min = count[j];
                }
            }

            for(int j = 0; j < n; j++){
                if((double)count[j] / i == hv){
                    winners.push_back(j);
                }
            }

            if(winners.size() == auxn) break;

            for(int j = 0; j < n; j++){
                if(min == count[j]){
                    invalid[j] = true;
                    auxn--;
                }
            }
            highestVote = hv;

        }
        for(int j = 0; j < winners.size(); j++){
            printf("%s", names[winners[j]]);
        }
        if(t){
            printf("\n");
        }
    }
    return 0;
}