1class Solution {
2public:
3    void Traversal(TreeNode* root, vector<vector<int>>& vc) {
4        if (!root) return;
5        queue<TreeNode*> q;
6        q.push(root);
7        while (!q.empty()) {
8            int len = q.size();
9            vector<int> level;   
10            for (int i = 0; i < len; i++) {
11                TreeNode* top = q.front();
12                q.pop();
13                level.push_back(top->val);
14                if (top->left) q.push(top->left);
15                if (top->right) q.push(top->right);
16            }
17            vc.push_back(level);
18        }
19    }
20
21    vector<vector<int>> levelOrder(TreeNode* root) {
22        vector<vector<int>> vc;
23        Traversal(root,vc);
24        return vc;
25    }
26};
27