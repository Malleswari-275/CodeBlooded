1/**
2 * Definition for a binary tree node.
3 * struct TreeNode {
4 *     int val;
5 *     TreeNode *left;
6 *     TreeNode *right;
7 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
8 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
9 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
10 * };
11 */
12class Solution {
13public:
14    void Vertical(TreeNode* root, map<int,vector<pair<int,int>>>& mp, int col, int level){
15        if(!root) return;
16        mp[col].push_back({level,root->val});
17        Vertical(root->left,mp,col-1,level+1);
18        
19        Vertical(root->right,mp,col+1,level+1);
20        
21    }
22    
23    static bool comp(pair<int,int>&a , pair<int,int>&b){
24
25        if(a.first < b.first) return true;
26
27        if(a.first == b.first){
28            return a.second<b.second;
29        }
30
31        return false;
32
33    }
34    vector<vector<int>> verticalTraversal(TreeNode* root) {
35        map<int,vector<pair<int,int>>>mp;
36        Vertical(root,mp,0,0);
37
38        vector<vector<int>>res;
39        
40        for(auto &it : mp){
41            
42            vector<pair<int,int>>tmp = it.second;
43
44            sort(tmp.begin(),tmp.end(),comp);
45
46            vector<int>tmp2;
47
48            for(int i=0;i<tmp.size();i++){
49                tmp2.push_back(tmp[i].second);
50            }
51
52            res.push_back(tmp2);
53        }
54        return res;
55    }
56    
57};