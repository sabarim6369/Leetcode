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
  vector<vector<int>>vc;
    void helper(TreeNode* root,int targetsum,int currsum,vector<int>inner){
        if(!root)return;
        currsum+=root->val;
        inner.push_back(root->val);
        if(!root->left && !root->right && currsum==targetsum){
            vc.push_back(inner);
            return;
        }
        helper(root->left,targetsum,currsum,inner);
        helper(root->right,targetsum,currsum,inner);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        helper(root,targetSum,0,{});
        return vc;
    }
};