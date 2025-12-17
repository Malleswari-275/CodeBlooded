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
14    vector<int>vc;
15    void inorder(TreeNode* root){
16        if(!root) return;
17        inorder(root->left);
18        vc.push_back(root->val);
19        inorder(root->right);
20    }
21    void Inorder(TreeNode* &root, int& i){
22        if(!root) return;
23        Inorder(root->left,i);
24        root->val = vc[i];
25        i++;
26        Inorder(root->right,i);
27    }
28    void recoverTree(TreeNode* root) {
29        inorder(root);
30        sort(vc.begin(),vc.end());
31        int i = 0;
32        Inorder(root,i);
33    }
34};