1class Solution {
2public:
3    int numOfPairs(vector<string>& nums, string target) {
4        int ans = 0;
5        for(int i = 0; i < nums.size(); i++){
6            for(int j = 0; j < nums.size(); j++){
7                if(i != j){
8                    if(nums[i] + nums[j] == target) ans++;
9                }
10            }
11        }
12        return ans;
13    }
14};