1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long ans = 0;
5        long long mini = nums[0];
6        long long maxi = nums[0];
7        for(int i = 1; i < nums.size(); i++){
8            if(nums[i] < mini) mini = nums[i];
9            else if(nums[i] > maxi) maxi = nums[i];
10            ans = max(ans, (maxi-mini));
11        }
12        return k*ans;
13    }
14};