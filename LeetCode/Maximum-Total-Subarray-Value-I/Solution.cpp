1class Solution {
2public:
3    long long maxTotalValue(vector<int>& nums, int k) {
4        long long mini= *min_element(nums.begin(),nums.end());
5        long long maxi = *max_element(nums.begin(),nums.end());
6        return (maxi-mini)*k;
7    }
8};