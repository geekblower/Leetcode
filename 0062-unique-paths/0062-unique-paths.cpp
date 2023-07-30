class Solution {
public:
    int countPaths(vector< vector<int> > &visited, int x, int y, int m, int n) {
        if(x==m-1 || y==n-1) {
            return 1;
        }

        if(visited[x][y] != 0) {
            return visited[x][y];
        }

        int right = countPaths(visited, x, y+1, m, n);
        int down = countPaths(visited, x+1, y, m, n);

        visited[x][y] = right + down;

        return visited[x][y];
    }

    int uniquePaths(int m, int n) {
        vector< vector<int> > visited(m, vector<int> (n,0));
        int count = 0;

        count = countPaths(visited, 0, 0, m, n);

        return count;
    }
};