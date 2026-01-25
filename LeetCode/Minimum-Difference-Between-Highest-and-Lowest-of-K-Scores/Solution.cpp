1class Solution {
2public:
3    int minimumDifference(vector<int>& nums, int k) {
4        sort(nums.begin(),nums.end());
5        int mini = INT_MAX;
6        for(int i = 0; i+k-1 < nums.size(); i++){
7            mini = min(mini,nums[i+k-1]-nums[i]);
8        }
9        return mini;
10    }
11};