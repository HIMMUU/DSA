class Solution {
private:
    bool check(vector<vector<int>>& mat, int i, int j) {
        int n = mat.size();
        int m = mat[0].size();
        bool b1 = false, b2 = false, b3 = false, b4 = false;

        // if (mat[i - 1][j] < mat[i][j] && mat[i + 1][j] < mat[i][j] &&
        //     mat[i][j + 1] < mat[i][j] && mat[i][j - 1] < mat[i][j]) {
        //     return true;
        // }
        if( i-1 < 0 || mat[i - 1][j] < mat[i][j]) b1 = true ;
        if( i+1 >= n || mat[i +1][j] < mat[i][j]) b2 = true ; 
        if( j+1 >= m ||  mat[i][j + 1] < mat[i][j]) b3 = true ;
        if(j-1 < 0  || mat[i][j-1] < mat[i][j]) b4 = true ; 
        if( b1 && b2 && b3 && b4) return true ;
        else return false;
    }

public:
    vector<int> findPeakGrid(vector<vector<int>>& mati) {
        int n = mati.size();
        int m = mati[0].size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (check(mati, i, j)) {
                    return {i, j};
                }
            }
        }
        return {0, 0};
    }
};