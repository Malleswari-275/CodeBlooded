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
14    int BFS(TreeNode* root){
15        if(!root) return 0;
16
17        queue<TreeNode*>q;
18        q.push(root);
19        int level = 0;
20
21        while(!q.empty()){
22            int len = q.size();
23            for(int i = 0; i < len; i++){
24                TreeNode* node = q.front();
25                q.pop();
26                if(node->left) q.push(node->left);
27                if(node->right) q.push(node->right);
28            }
29            level++;
30        }
31        return level;
32    }
33    int maxDepth(TreeNode* root) {
34        return BFS(root);
35    }
36};