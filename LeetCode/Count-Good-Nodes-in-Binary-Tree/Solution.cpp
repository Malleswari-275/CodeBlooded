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
14    int cnt = 0;
15    void inorder(TreeNode* root, int maxi){
16        if(!root) return;
17        maxi = max(maxi,root->val);
18        if(maxi == root->val) cnt++;
19        inorder(root->left,maxi);
20        inorder(root->right,maxi);
21    }
22    int goodNodes(TreeNode* root) {
23        inorder(root,INT_MIN);
24        return cnt;
25    }
26};