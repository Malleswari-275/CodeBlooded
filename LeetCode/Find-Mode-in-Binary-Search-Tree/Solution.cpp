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
14    void inorder(TreeNode* root, unordered_map<int,int>& mp){
15        if(!root) return;
16        mp[root->val]++;
17        inorder(root->left,mp);
18        inorder(root->right,mp);
19    }
20    vector<int> findMode(TreeNode* root) {
21        unordered_map<int,int>mp;
22        inorder(root,mp);
23
24        int maxi = 0;
25        for(auto [key,val] : mp){
26            maxi = max(maxi,val);
27        }
28        vector<int>vc;
29
30        for(auto [key,val]: mp){
31            if(val == maxi) vc.push_back(key);
32        }
33        return vc;
34    }
35};