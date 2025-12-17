1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int n = prices.size();
5        if (n <= 1) return 0;
6        int minPrice = prices[0];
7        int maxProfit = 0;
8        for (int i = 1; i < n; i++) {
9            int profit = prices[i] - minPrice;
10            maxProfit = max(maxProfit, profit);
11            minPrice = min(minPrice, prices[i]);
12        } 
13        return maxProfit;
14    }
15};
16