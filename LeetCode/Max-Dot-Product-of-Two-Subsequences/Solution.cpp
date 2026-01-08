1class Solution {
2public:
3    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
4
5        int m = nums1.size();
6        int n = nums2.size();
7        vector<vector<int>> dp(m+1,vector<int>(n+1, INT_MIN));
8
9        
10        for(int i = 1; i < dp.size(); i++){
11
12            for(int j = 1; j < dp[i].size(); j++){
13
14                int product = nums1[i-1]*nums2[j-1];
15                // dp[i][j] = product;
16
17                dp[i][j] = max(product+max(0,dp[i-1][j-1]), dp[i-1][j-1]);
18                dp[i][j] = max(dp[i][j], dp[i][j-1]);
19                dp[i][j] = max(dp[i-1][j],dp[i][j]);
20            }
21        }
22        return dp[m][n];
23    }
24};