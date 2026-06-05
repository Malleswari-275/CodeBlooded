1class Solution {
2public:
3    vector<int> sortArray(vector<int>& nums) {
4        int maxi = *max_element(nums.begin(),nums.end());
5        int mini = *min_element(nums.begin(),nums.end());
6        vector<int>pref(maxi-mini+1,0);
7        vector<int>freq(maxi-mini+1,0);
8        vector<int>ans(nums.size());
9        for(int i = 0; i < nums.size(); i++) freq[nums[i]-mini]++;
10        pref[0] = freq[0];
11        for(int i = 1; i < maxi-mini+1; i++) pref[i] = freq[i]+pref[i-1];
12
13        for(int i = nums.size()-1; i >= 0; i--){
14            if(freq[nums[i]-mini] > 0){
15                ans[pref[nums[i]-mini]-1] = nums[i];
16                freq[nums[i]-mini]--;
17                pref[nums[i]-mini]--;
18            }
19        }
20        return ans;
21    }
22};