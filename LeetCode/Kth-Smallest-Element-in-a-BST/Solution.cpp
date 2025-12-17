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
14    int i = 0;
15    void inorder(TreeNode* root, int k, int& ans){
16        if(!root) return;
17        inorder(root->left,k,ans);
18        i++;
19        if(i == k){
20            ans = root->val;
21            return;
22        }
23        inorder(root->right,k,ans);
24    }
25    int kthSmallest(TreeNode* root, int k) {
26        int ans = 0;
27        inorder(root,k,ans);
28        return ans;
29    }
30};