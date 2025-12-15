1class Solution {
2public:
3    long long getDescentPeriods(vector<int>& prices) {
4        long long ans = prices.size();
5        long long cnt = 1;
6        for(int i = 1; i < prices.size(); i++){
7            if(prices[i-1]-prices[i] == 1) cnt++;
8            else{
9                ans += cnt*(cnt-1)/2;
10                cnt = 1;
11            }
12        }
13        ans += cnt*(cnt-1)/2;
14        return ans;
15    }
16};