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
    int countleft(TreeNode *node){
        if(!node)return 0;
        int count=0;
        while(node){
            count++;
            node=node->left;
        }
        return count;

    }
    int countright(TreeNode* node){
        if(!node)return 0;
        int count=0;
        while(node){
            count++;
            node=node->right;
        }
        return count;

    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int leftheight=countleft(root->left)+1;
        int rightheight=countright(root->right)+1;
        if(leftheight==rightheight){
            return (1<<leftheight)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
};