1class Solution {
2public:
3    int climbStairs(int n) {
4        if (n == 0) return 1;
5        if (n == 1) return 1;
6
7        int dp[n + 1];
8        dp[0] = 1;
9        dp[1] = 1;
10
11        for (int i = 2; i <= n; i++) {
12        dp[i] = dp[i - 1] + dp[i - 2];
13        }
14        return dp[n];
15    }
16};