class Solution {
public:
    unordered_map<int, bool> rowCheck;
    unordered_map<int, bool> colCheck;
    unordered_map<int, bool> leftUpperCheck;
    unordered_map<int, bool> leftLowerCheck;

    void makeSolution(vector<vector<string>> &solution, vector<vector<char>> &board, int n) {
        vector<string> answer;

        for(vector<char> i : board) {
            string temp;
            for(char j : i) {
                temp.push_back(j);
            }
            answer.push_back(temp);
        }

        solution.push_back(answer);
    }

    bool isSafe(int col, int row, vector<vector<char>> &board, int n) {
        return !(rowCheck[row] || colCheck[col] || leftUpperCheck[n+row-col] || leftLowerCheck[row+col]);
    }

    void solve(int col, vector<vector<string>> &solution, vector<vector<char>> &board, int n) {
        if(col == n) {
            makeSolution(solution, board, n);
            return;
        }

        for(int row=0; row<n; row++) {
            if(isSafe(col, row, board, n)) {
                board[row][col] = 'Q';
                rowCheck[row] = true;
                colCheck[col] = true;
                leftUpperCheck[n+row-col] = true;
                leftLowerCheck[row+col] = true;

                solve(col+1, solution, board, n);
                
                // Backtracking
                board[row][col] = '.';
                rowCheck[row] = false;
                colCheck[col] = false;
                leftUpperCheck[n+row-col] = false;
                leftLowerCheck[row+col] = false;
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solution;
        vector<vector<char>> board(n, vector<char> (n, '.'));

        solve(0, solution, board, n);
        
        return solution;
    }
};