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
   bool haspath(TreeNode* root,int targetsum,int currsum){
    if(!root)return 0;
    currsum+=root->val;
    if(!root->left&&!root->right&&currsum==targetsum){
        return true;
    }
    return haspath(root->left,targetsum,currsum)||haspath(root->right,targetsum,currsum);

   }
    bool hasPathSum(TreeNode* root, int targetSum) {
      return  haspath(root,targetSum,0);

        
    }
};