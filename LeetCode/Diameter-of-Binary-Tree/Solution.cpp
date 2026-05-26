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
14    int maxi = 0;
15    int dfs(TreeNode* root){
16        if(!root){
17            return 0;
18        }
19        int l = dfs(root->left);
20        int r = dfs(root->right);
21        maxi = max(maxi,l+r);
22        return 1 + max(l,r);
23    }
24    int diameterOfBinaryTree(TreeNode* root) {
25        dfs(root);
26        return maxi;
27    }
28};