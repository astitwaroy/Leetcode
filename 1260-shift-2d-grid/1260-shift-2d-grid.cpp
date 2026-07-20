class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int total = m * n;
        k %= total;
        vector<vector<int>>ans(m, vector<int>(n));
        for(int i = 0 ; i < m; i++){
            for(int j = 0; j < n; j++){
                int oldInd = i * n + j;
                int newInd = (oldInd + k) % total;
                ans[newInd / n][newInd % n] = grid[i][j];

            }
        }
        return ans;   
    }
};