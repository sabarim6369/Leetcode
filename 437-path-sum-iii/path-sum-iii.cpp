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
    int count=0;
    void dfs(TreeNode *root,long long currsum,int targetsum){
        if(!root)return;
        currsum+=root->val;
        if(currsum==targetsum){
            count++;
           
        }
        dfs(root->left,currsum,targetsum);
        dfs(root->right,currsum,targetsum);

    }
    void countpath(TreeNode *root,int targetsum){
        if(!root)return;
        dfs(root,0,targetsum);
        countpath(root->left,targetsum);
        countpath(root->right,targetsum);

    }
    
    int pathSum(TreeNode* root, int targetSum) {
        countpath(root,targetSum);
        return count;
         
        
    }
};