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
14    long long totalSum = 0;
15    void TotalSum(TreeNode* root){
16        if(!root) return;
17        totalSum += root->val;
18        TotalSum(root->left);
19        TotalSum(root->right);
20    }
21    long long maxi = INT_MIN;
22    int curr = 0;
23    long long inorder(TreeNode* root){
24        if(!root) return 0;
25        long long lt =  inorder(root->left);
26        long long rt = inorder(root->right);
27        curr = lt + rt + root->val;
28        maxi = max(maxi,(totalSum - curr)*curr);
29        return curr;
30    }
31    const int mod = 1e9 + 7;
32    int maxProduct(TreeNode* root) {
33        TotalSum(root);
34        inorder(root);
35        return maxi%mod;
36    }
37};