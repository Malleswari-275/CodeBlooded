1class Solution {
2public:
3    int findMiddleIndex(vector<int>& nums) {
4        int n = nums.size();
5        for(int i = 1; i < n; i++){
6            nums[i] += nums[i-1];
7        }
8        if(nums[0] == nums[n-1]) return 0;
9        else{
10            for(int i = 1; i < n; i++){
11                if(nums[i-1] == nums[n-1] - nums[i]) return i;
12            }
13        }
14        return -1;
15    }
16};