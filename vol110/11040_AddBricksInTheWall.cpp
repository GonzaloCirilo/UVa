#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        vector<vector<int>> pyramid = vector<vector<int>>(), ans = vector<vector<int>>(9, vector<int>());
        for(int i = 0; i < 5; i++) {
            vector<int> aux = vector<int>();
            for(int j = 0; j < i + 1; j++) {
                cin >> n;
                aux.push_back(n);
            }
            pyramid.push_back(aux);
        }

        ans[0] = pyramid[0];
        for(int i = 2; i < 9; i+=2){
            vector<int>aux = vector<int>();
            for(int j = 0; j <= i; j++){
                if(j % 2 == 0) {
                    aux.push_back(pyramid[i/2][j/2]);
                }else{
                    int result = pyramid[(i/2) - 1][(j/2)] - (pyramid[i/2][j/2]) -  (pyramid[i/2][(j/2) + 1]);
                    aux.push_back(result/2);
                }
            }
            ans[i] = aux;
        }

        for(int i = 1; i < 9; i+=2){
            vector<int>aux = vector<int>();
            for(int j = 0; j <= i; j++){
                int result = ans[i + 1][j+1] + ans[i + 1][j];
                aux.push_back(result);
                
            }
            ans[i] = aux;
        }

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < ans[i].size(); j++){
                if(j != 0) cout << " ";
                cout << ans[i][j];
            }
            cout << endl;
        }
    }
    return 0;
}