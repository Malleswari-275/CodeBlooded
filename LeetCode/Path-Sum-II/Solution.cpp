/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int>vc;
    void PathSum(TreeNode* root, int targetSum, vector<vector<int>>& Paths){
        if(!root) return;
        // pre order
        vc.push_back(root->val);
        if(!root->left && !root->right){
            int currSum = accumulate(vc.begin(),vc.end(),0);
            if(currSum == targetSum) Paths.push_back(vc);
        }
        
        PathSum(root->left,targetSum,Paths);
        PathSum(root->right,targetSum,Paths);
        vc.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>Paths;
        PathSum(root,targetSum,Paths);
        return Paths;
    }
};