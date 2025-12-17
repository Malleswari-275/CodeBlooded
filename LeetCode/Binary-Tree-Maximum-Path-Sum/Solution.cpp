1class Solution {
2public:
3    int maxi = INT_MIN;
4
5    int fun(TreeNode* root) {
6        if (!root) return 0; 
7        int left = max(0, fun(root->left));  
8        int right = max(0, fun(root->right)); 
9        maxi = max(maxi, root->val + left + right);
10        return root->val + max(left, right);
11    }
12
13    int maxPathSum(TreeNode* root) {
14        fun(root);
15        return maxi;
16    }
17};
18