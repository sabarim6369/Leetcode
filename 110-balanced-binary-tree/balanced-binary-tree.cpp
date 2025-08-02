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
bool isbalanced=true;
     int maxdepth(TreeNode *node){
        if(!node)return 0;
        return 1+max(maxdepth(node->left),maxdepth(node->right));
     }
     void preorder(TreeNode *node){
        if(!node || !isbalanced)return;
        int left=maxdepth(node->left);
        int right=maxdepth(node->right);
        if(abs(left-right)>1){
            isbalanced=false;
            return;
        }
        preorder(node->left);
        preorder(node->right);
     }
    bool isBalanced(TreeNode* root) {
        preorder(root);
        return isbalanced;
       
        
    }
};