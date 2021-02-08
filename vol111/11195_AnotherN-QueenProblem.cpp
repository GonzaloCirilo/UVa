#include <stdio.h>
#include <vector>
using namespace std;
typedef vector<int> vi;
int correctShifting;
vi grid;

// bitset of the col, bitset of left diag, bitset of the right diag and row index
int bitwiseNQueens(int col, int ld, int rd, int row){ // ld has m = -1 and rd has m - 1
    if(col == 0){
        // 0 means forbidden col so if all bits are zero we have place all queens in valid positions
        return 1;
    }
    // (!) Generate possible values. The modification of the algorithm is that we add a 4th operator
    //    where we eliminate the forbidden cols by applying AND with the bitset from  row in the grid
    int poss = col & ld & rd & grid[row], res = 0;
    while(poss & -poss){// (2.1)iterate trough all ones in the bitset 
        //always taking the first 1 from the left cause of the operation (a & -a)
        int bit = poss & -poss; // (2.2) current bit (for n = 4 at first iteration: 0001)
        // (3) We update poss with and xor operation with the current bit
        // taking the first value from example above poss new value wil be 1110
        // Thus in the next it bit will be 0010
        poss ^= bit;
        // (4)
        // -the first param removes a col with the xor operation. Following the example 1111 ^ 0001 = 1110
        // -second param shift to the left after applying Xor to have 11100.The last OR 
        //  operator corrects the bitset to 11101. the 1 after the fourth posistion wil ne discarded in step 1 of next iteration
        // -Thir param applies a right shift after the xor leaving 0111. The OR  with correctShift, which value
        //  is 1000 for the example, gives the value of 1111 since its at the right edge, the right
        //  diagonal doesn't blocks any zone. The ANDs in the second and third parameter serve the purpose 
        //  to block only the only diagonal position for the next iteration
        res += bitwiseNQueens(col ^ bit, (ld ^ bit) << 1 | 1, (rd ^ bit) >> 1 | correctShifting, row + 1);
    }
    return res;
}

// Solved with flipedBitwiseNQueens algo
int main(){
    int n, cont = 1;

    while(scanf("%d\n", &n) && n){
        // For each row we will store the forbidden zones in a bitset
        grid.clear();
        
        for(int i = 0; i < n; i++){
            int aux = 0;
            for(int j = 0; j < n; j++){
                char c = getchar();
                if(c == '*') // if we found a blocked zone we shift to left according to the formula
                    aux += (1 << (n - j - 1));
            }
            // We have to negate the bitset since 1 means that it can be placed
            // ans 0 tha it can't be placed there
            // e.g. given the first row of a 4x4 matrix: .**.
            // the bits in aux will be 0110, then we negate to get 1001
            grid.push_back(~aux);
            getchar();
        }

        correctShifting = 1 << (n - 1); 

        // all cols and diagonals should have 1s in their bit set
        int ans = bitwiseNQueens((1 << n) - 1, (1 << n) - 1, (1 << n) - 1, 0);

        printf("Case %d: %d\n", cont++, ans, 0);
    }

    return 0;
}