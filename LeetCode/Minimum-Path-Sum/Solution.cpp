1class Solution {
2public:
3    int MinPath(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
4        if(i == 0 && j == 0) return grid[i][j];
5        if(i < 0 || j < 0) return 1e9;
6        if(dp[i][j] != -1) return dp[i][j];
7
8        int left = grid[i][j] + MinPath(i,j-1,grid,dp);
9        int up = grid[i][j] + MinPath(i-1,j,grid,dp);
10        return dp[i][j] = min(left,up);
11    }
12    int minPathSum(vector<vector<int>>& grid) {
13        vector<vector<int>>dp(grid.size(), vector<int>(grid[0].size(),-1));
14        int minimum_distance = MinPath(grid.size()-1, grid[0].size()-1, grid, dp);
15        return minimum_distance;
16    }
17};