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
    bool issame=true;
    void helper(TreeNode *p,TreeNode *q){
         if ((!p && q) || (p && !q) || !issame) {
            issame = false;
            return;
        }
     if (!p && !q) return;

        if(p->val!=q->val){
            issame=false;
            return;
        }
        helper(p->left,q->left);
        helper(p->right,q->right);
       
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
         helper(p,q);
         return issame;
    }
};