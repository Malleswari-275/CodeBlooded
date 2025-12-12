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
14    int mini = INT_MAX;
15    void Traversal(TreeNode* root, int val){
16        if(!root) return;
17        val++;
18        if(!root->left && !root->right) mini = min(mini,val);
19        Traversal(root->left,val);
20        Traversal(root->right,val);
21    }
22    int minDepth(TreeNode* root) {
23        if(!root) return 0;
24        Traversal(root,0);
25        return mini;
26    }
27};