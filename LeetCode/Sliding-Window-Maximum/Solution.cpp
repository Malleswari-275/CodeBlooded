1class Solution {
2public:
3    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
4        multiset<int>ms;
5        vector<int>vc;
6        for(int i = 0; i < k; i++) ms.insert(nums[i]);
7        for(int i = k; i < nums.size(); i++){
8            vc.push_back(*ms.rbegin());
9            ms.erase(ms.find(nums[i-k]));
10            ms.insert(nums[i]);
11        }
12        vc.push_back(*ms.rbegin());
13        return vc;
14    }
15};