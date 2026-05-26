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
14    int maxi = INT_MIN;
15    void inorder(TreeNode* root, int curr){
16        if(!root){
17            maxi = max(maxi,curr);
18            return;
19        }
20        curr += 1;
21        inorder(root->left,curr);
22        inorder(root->right,curr);
23    }
24    int maxDepth(TreeNode* root) {
25        inorder(root,0);
26        return maxi;
27    }
28};