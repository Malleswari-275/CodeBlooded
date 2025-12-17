1class Solution {
2public:
3    int maxSubArray(vector<int>& nums) {
4        int curr_max = nums[0];
5        int global_max = nums[0];
6        for(int i = 1; i < nums.size(); i++){
7            curr_max = max(nums[i], nums[i] + curr_max);
8            global_max = max(curr_max, global_max);
9        }
10        return global_max;
11    }
12};