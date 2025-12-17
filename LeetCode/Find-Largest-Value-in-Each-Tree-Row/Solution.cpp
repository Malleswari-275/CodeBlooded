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
15    void BFS(TreeNode* root){
16        queue<TreeNode*>q;
17        q.push(root);
18
19        while(!q.empty()){
20            int len = q.size();
21            int maxi = INT_MIN;
22            for(int i = 0; i < len; i++){
23                TreeNode* top = q.front();
24                q.pop();
25                maxi = max(maxi,top->val);
26                if(top->left) q.push(top->left);
27                if(top->right) q.push(top->right);
28            }
29            vc.push_back(maxi);
30        }
31    }
32    vector<int> largestValues(TreeNode* root) {
33        if(!root) return {};
34        BFS(root);
35        return vc;
36    }
37};