1class Solution {
2public:
3    int countPartitions(vector<int>& nums) {
4        for(int i = 1; i < nums.size(); i++) nums[i] = nums[i]+nums[i-1];
5        int cnt = 0;
6        for(int i = 0; i < nums.size()-1; i++){
7            if(((nums[nums.size()-1] - nums[i]) - nums[i])%2 == 0) cnt++;
8        }
9        return cnt;
10    }
11};