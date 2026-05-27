1class Solution {
2public:
3    vector<vector<int>>result;
4    void BT(vector<int>&nums,vector<bool>&visited, vector<int>&vc){
5        if(vc.size() == nums.size()){
6            result.push_back(vc);
7            return;
8        }
9        for(int i = 0; i < nums.size(); i++){
10            if(!visited[i]){
11                vc.push_back(nums[i]);
12                visited[i] = true;
13
14                BT(nums,visited,vc);
15
16                vc.pop_back();
17                visited[i] = false;
18            }
19        }
20    }
21    vector<vector<int>> permute(vector<int>& nums) {
22        vector<bool>vis(nums.size(),false);
23        vector<int>vc;
24        BT(nums,vis,vc);
25        return result;
26    }
27};