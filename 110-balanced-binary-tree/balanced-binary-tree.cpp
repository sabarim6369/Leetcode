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
// bool isbalanced=true;
//      int maxdepth(TreeNode *node){
//         if(!node)return 0;
//         return 1+max(maxdepth(node->left),maxdepth(node->right));
//      }
//      void postorder(TreeNode *node){
//         if(!node || !isbalanced)return;
//         int left=maxdepth(node->left);
//         int right=maxdepth(node->right);
//         if(abs(left-right)>1){
//             isbalanced=false;
//             return;
//         }
//         preorder(node->left);
//         preorder(node->right);
//      }
//     bool isBalanced(TreeNode* root) {
//         postorder(root);
//         return isbalanced;
       
        
//     }
// };
int dfs(TreeNode *node){
    if(!node)return 0;
    int left=dfs(node->left);
    if(left==-1)return -1;
    int right=dfs(node->right);
    if(right==-1)return -1;
    if(abs(left-right)>1)return -1;
    return 1+max(left,right);

}
 bool isBalanced(TreeNode* root) {
       return dfs(root)!=-1;
        
    }
};