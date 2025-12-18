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
14    vector<vector<int>>vc;
15    void BFS(TreeNode* root){
16
17        queue<TreeNode*>q;
18        q.push(root);
19
20        while(!q.empty()){
21            int len = q.size();
22            vector<int>arr;
23            for(int i= 0; i < len; i++){
24                TreeNode* top = q.front();
25                q.pop();
26                if(top->left)q.push(top->left);
27                if(top->right) q.push(top->right);
28                arr.push_back(top->val);
29            }
30            vc.push_back(arr);
31        }
32    }
33    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
34        if(!root) return {};
35        BFS(root);
36        for(int i = 1; i < vc.size(); i+=2){
37            reverse(vc[i].begin(),vc[i].end());
38        }
39        return vc;
40    }
41};