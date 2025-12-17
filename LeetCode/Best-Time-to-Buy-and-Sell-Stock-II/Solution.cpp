1class Solution {
2public:
3    int maxProfit(vector<int>& prices) {
4        int total_profit = 0;
5        for(int i = 1; i < prices.size(); i++){
6            if(prices[i] > prices[i-1]) total_profit += prices[i]-prices[i-1];
7        }
8        return total_profit;
9    }
10};