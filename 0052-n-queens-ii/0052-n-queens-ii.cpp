class Solution {
public:
    unordered_map<int,bool> rowCheck;
    unordered_map<int,bool> leftUpperCheck;
    unordered_map<int,bool> leftLowerCheck;

    bool isSafe(int row, int col, int n) {
        return !(rowCheck[row] || leftUpperCheck[n+row-col] || leftLowerCheck[row+col]);
    }

    void queens(int col, vector< vector<int> > &board, int &count, int n) {
        if(col == n) {
            count++;
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(row, col, n)) {
                board[row][col] = 1;

                rowCheck[row] = true;
                leftUpperCheck[n+row-col] = true;
                leftLowerCheck[row+col] = true;

                queens(col+1, board, count, n);

                board[row][col] = 0;
                rowCheck[row] = false;
                leftUpperCheck[n+row-col] = false;
                leftLowerCheck[row+col] = false;              
            }
        }
    }

    int totalNQueens(int n) {
        vector< vector<int> > board(n, vector<int> (n, 0));
        int count = 0;

        queens(0, board, count, n);

        return count;
    }
};