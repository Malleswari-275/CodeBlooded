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
14    vector<vector<int>> BFS(TreeNode* root){
15        if(!root) return {};
16        queue<TreeNode*>q;
17        q.push(root);
18        vector<vector<int>>vc;
19        int level = 0;
20        while(!q.empty()){
21            int len = q.size();
22            vc.push_back({});
23            for(int i = 0; i < len; i++){
24                TreeNode* node = q.front();
25                q.pop();
26                if(node){
27                    vc[level].push_back(node->val);
28                    q.push(node->left);
29                    q.push(node->right);
30                }
31                else vc[level].push_back(-200);
32                
33            }
34            level++;
35        }
36        return vc;
37    }
38    bool isSymmetric(TreeNode* root) {
39        // BFS of a binary tree
40        vector<vector<int>>vc = BFS(root);
41        for(int i = 0; i < vc.size(); i++){
42            for(int j = 0; j < vc[i].size(); j++){
43                if(vc[i][j] != vc[i][vc[i].size()-j-1]) return false;
44                cout<<vc[i][j]<<" ";
45            }
46            cout<<endl;
47        }
48        return true;
49    }
50};