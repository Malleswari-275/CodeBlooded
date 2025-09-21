class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        long long ans = 0;
        long long mini = nums[0];
        long long maxi = nums[0];
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < mini) mini = nums[i];
            else if(nums[i] > maxi) maxi = nums[i];
            ans = max(ans, (maxi-mini));
        }
        return k*ans;
    }
};