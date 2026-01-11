1class Solution {
2public:
3    int centeredSubarrays(vector<int>& nums) {
4        int cnt = 0;
5        for(int i = 0; i < nums.size(); i++){
6            vector<int>vc;
7            int sum = 0;
8            for(int j = i; j < nums.size(); j++){
9                vc.push_back(nums[j]);
10                sum += nums[j];
11                if(find(vc.begin(),vc.end(),sum) != vc.end()) cnt++;
12            }
13        }
14        return cnt;
15    }
16};