class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int r0 = mat.size();
        int c0 = mat[0].size();
        
        if(r0*c0 != r*c)
            return mat;

        vector<int> v0(c);
        vector<vector<int>> v(r, v0);

        for(int i=0; i<r0*c0; ++i) {
            v[i/c][i%c] = mat[i/c0][i%c0];
        }

        return v;
    }
};



/*
class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans;
        
        int row = mat.size();
        int col = mat[0].size();
        
        vector<int> line;
        
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                line.push_back (mat[i][j]);
            }
        }
        
        int count=0;
        
        for(int i=0; i<r; i++) {
            vector<int> temp;
            for(int j=0; j<c; j++) {
                temp.push_back (line[count]);
                count++;
            }
            ans.push_back (temp);
        }
        
        return ans;
    }
};
*/
    
    
    
