1class Solution {
2public:
3    int cnt = 0;
4    
5    int paths(int m, int n, int i, int j, vector<vector<int>>&dp){
6        if(i == m-1 && j == n-1){
7            // cnt += 1;
8            return 1;
9        }
10        if(i >= m || j >= n) return 0;
11        if(dp[i][j] != -1) return dp[i][j];
12        int l = paths(m,n,i+1,j,dp);
13        int r = paths(m,n,i,j+1,dp);
14        return dp[i][j] = l+r;
15    }
16    int uniquePaths(int m, int n) {
17        vector<vector<int>>dp(m,vector<int>(n,-1));
18        return paths(m,n,0,0,dp);
19        
20    }
21};