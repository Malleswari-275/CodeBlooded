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
14    void Traversal(TreeNode* root, vector<vector<int>>& vc) {
15        if (!root) return;
16        queue<TreeNode*> q;
17        q.push(root);
18        while (!q.empty()) {
19            int len = q.size();
20            vector<int> level;   
21            for (int i = 0; i < len; i++) {
22                TreeNode* top = q.front();
23                q.pop();
24                level.push_back(top->val);
25                if (top->left) q.push(top->left);
26                if (top->right) q.push(top->right);
27            }
28            vc.push_back(level);
29        }
30    }
31    vector<vector<int>> levelOrderBottom(TreeNode* root) {
32        vector<vector<int>>vc;
33        Traversal(root,vc);
34        reverse(vc.begin(),vc.end());
35        return vc;
36    }
37};