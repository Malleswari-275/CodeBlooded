1class Solution {
2public:
3    int singleNonDuplicate(vector<int>& nums) {
4        int low = 0, high = nums.size()-1;
5        int mid;
6        while(low < high){
7            mid = low + (high-low)/2;
8            if(mid%2 != 0) mid--;
9            if(nums[mid] == nums[mid+1]) low = mid+2;
10            else high = mid-1;
11            
12        }
13        return nums[low];
14    }
15};