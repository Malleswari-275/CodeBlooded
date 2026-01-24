1class Solution {
2public:
3    int minPairSum(vector<int>& nums) {
4        sort(nums.begin(),nums.end());
5        int n = nums.size();
6        int maxi = INT_MIN;
7        for(int i = 0; i < n/2; i++){
8            maxi = max(maxi,nums[i]+nums[n-i-1]);
9        }
10        return maxi;
11    }
12};