#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
    string line;
    map <char, char> mirror = { 
        {'A', 'A'}, {'E', '3'}, {'3', 'E'}, {'H', 'H'}, {'I', 'I'}, {'J', 'L'}, {'M', 'M'}, {'O', 'O'},
        {'S', '2'}, {'S', '2'}, {'T', 'T'}, {'U', 'U'}, {'V', 'V'}, {'W', 'W'}, {'X', 'X'}, {'Y', 'Y'},
        {'Z', '5'}, {'1', '1'}, {'2', 'S'}, {'5', 'Z'}, {'8', '8'}, {'L', 'J'},
        };
    while(cin >> line){
        int mid = line.size() / 2, end = line.size() - 1;
        //cout << mid << endl;
        bool isPalindrome = true, isMirrored = true;
        for(int i = 0; i <= mid; i++){
            isPalindrome = isPalindrome && line[i] == line[end - i];
            if(mirror.find(line[i]) != mirror.end()){
                isMirrored = isMirrored && mirror[line[i]] == line[end-i];
            } else {
                isMirrored = false;
            }
        }
        cout << line << " -- is ";
        if(isMirrored && isPalindrome){
            cout << "a mirrored palindrome.";
        } else if(isMirrored) {
            cout << "a mirrored string.";
        } else if(isPalindrome) {
            cout << "a regular palindrome.";
        } else {
            cout << "not a palindrome.";
        }
        cout << endl << endl;
    }
    return 0;
}
