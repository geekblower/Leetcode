class Solution {
public:
    bool validate(int row, int col, vector<vector<char>> board) {
        char val = board[row][col];

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

    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0; row<9; row++) {
            for(int col=0; col<9; col++) {
                if(board[row][col] == '.') {
                    continue;
                }

                bool temp = validate(row, col, board);

                if(temp == false) {
                    return temp;
                }
            }
        }

        return true;

    }
};