class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();
        
        queue<pair<int,int>> togo;
        vector<int> dir = {0,1,0,-1,0};
        
        int count=0;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(mat[i][j]==0)
                    togo.emplace(i,j);
                else {
                    count++;
                    mat[i][j] = -1;
                }
            }
        }
        
        if(count==0)
            return mat;
        
        while(!togo.empty()){
            auto it = togo.front();
            togo.pop();
            int r = it.first;
            int c = it.second;
            for (int i=0; i<4; ++i) {
                int rr = r + dir[i];
                int cc = c + dir[i+1];
                
                if(rr<0 || cc<0 || rr>=row || cc>=col || mat[rr][cc]!=-1)
                    continue;
                
                mat[rr][cc] = mat[r][c]+1;
                togo.emplace(rr,cc);
            }
        }
        
        return mat;
    }
};