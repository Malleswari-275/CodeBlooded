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
15    void inorder(TreeNode* root, int &curr){
16        if(!root){
17            maxi = max(maxi,curr);
18            return;
19        }
20        curr += 1;
21        cout<<curr<<endl;
22        inorder(root->left,curr);
23        inorder(root->right,curr);
24        curr -= 1;
25    }
26    int maxDepth(TreeNode* root) {
27        int c = 0;
28        inorder(root,c);
29        return maxi;
30    }
31};