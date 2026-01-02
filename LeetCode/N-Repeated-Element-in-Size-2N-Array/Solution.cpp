1class Solution {
2public:
3    int repeatedNTimes(vector<int>& nums) {
4        int n = (nums.size())/2;
5        unordered_map<int,int>mp;
6        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
7        for(auto it : mp) if(it.second == n) return it.first;
8        return 0;
9    }
10};