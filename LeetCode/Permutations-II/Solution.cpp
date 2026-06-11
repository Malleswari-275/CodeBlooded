1class Solution {
2public:
3    map<vector<int>,int>mp;
4    void permute(vector<int>&nums,int idx, vector<int>&curr, vector<bool>&vis){
5        if(curr.size() == nums.size()){
6            mp[curr]++;
7            return;
8        }
9        for(int i =0 ; i < nums.size(); i++){
10            if(!vis[i]){
11                vis[i] = true;
12                curr.push_back(nums[i]);
13                permute(nums,i+1,curr,vis);
14                curr.pop_back();
15                vis[i] = false;
16            }
17        }
18    }
19    vector<vector<int>> permuteUnique(vector<int>& nums) {
20        vector<bool>vis(nums.size(),false);
21        vector<int>curr;
22        vector<vector<int>>vc;
23        permute(nums,0,curr,vis);
24        
25        for(auto it : mp) vc.push_back(it.first);
26        return vc;
27    }
28};