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
int maxsum=INT_MIN;
    int diameter(TreeNode *node){
        if(!node)return 0;
        int leftsum=max(0,diameter(node->left));
        int rightsum=max(0,diameter(node->right));
        maxsum=max(maxsum,leftsum+rightsum+node->val);
        return node->val+max(leftsum,rightsum);

    }
    int maxPathSum(TreeNode* root) {
         diameter(root);
         return maxsum;
    }
};