1class Solution {
2public:
3    vector<vector<int>>vc;
4    void backtrack(vector<int>& candidates, int target, vector<int>&curr, int idx){
5
6        if(target == 0){
7            vc.push_back(curr);
8            return;
9        }
10        if(target < 0){
11            return;
12        }
13        if(idx >= candidates.size()) return;
14        // pick same
15        curr.push_back(candidates[idx]);
16        backtrack(candidates,target-candidates[idx],curr,idx);
17        curr.pop_back();
18
19        // non pick or pick different
20        backtrack(candidates,target,curr,idx+1);
21    }
22    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
23        vector<int>curr;
24        backtrack(candidates,target,curr,0);
25        return vc;
26    }
27};