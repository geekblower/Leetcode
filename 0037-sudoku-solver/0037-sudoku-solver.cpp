class Solution {
private:
    bool validate(int row, int col, vector<vector<char>> board, char val) {
        for(int i=0; i<9; i++) {
            // For row
            if(board[row][i] == val) {
                if(i != col)
                    return false;
            }

            // For column
            if(board[i][col] == val) {
                if(i != row)
                    return false;
            }

            // For 3x3 matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == val) {
                if(((3*(row/3) + i/3) != row) && ((3*(col/3) + i%3) != col))
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>>& board) {
        
        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {

                // As '.' is denoting empty cells
                if(board[row][col] == '.') {

                    for(char ch='1'; ch<='9'; ch++) {
                        if(validate(row, col, board, ch)) {
                            board[row][col] = ch;

                            bool nextSolution = solve(board);

                            if(nextSolution) {
                                return true;
                            } else {
                                // Backtracking
                                board[row][col] = '.';
                            }
                        }
                    }

                    return false;

                }

            }
        }

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};