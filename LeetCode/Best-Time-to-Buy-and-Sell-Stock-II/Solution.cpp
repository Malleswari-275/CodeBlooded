1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int profit = 0;
5        for(int i = 1; i < prices.size(); i++){
6            if(prices[i] > prices[i-1]) profit += prices[i]-prices[i-1];
7        }
8        return profit;
9    }
10};