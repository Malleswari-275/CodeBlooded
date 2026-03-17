1class Solution {
2public:
3    int minSubArrayLen(int target, vector<int>& nums) {
4        int i = 0;
5        int ans = INT_MAX;
6        int sum = 0;
7        for(int j = 0;j < nums.size(); j++){
8            sum += nums[j];
9            while(sum >= target && j<nums.size()){
10                ans = min(ans,j-i+1);
11                sum -= nums[i];
12                i++;
13            }
14        }
15        return ans == INT_MAX ? 0 : ans;
16    }
17};