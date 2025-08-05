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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*,unsigned long long>>q;
        if(!root){
            return 0;
        }
        q.push({root,1});
        int maxwidth=0;
        while(!q.empty()){
            int size=q.size();
           unsigned long long first,last;
           for(int i=0;i<size;i++){
            auto[node,index]=q.front();
            if(i==0)first=index;
            if(i==size-1)last=index;
            q.pop();
            if(node->left){
                q.push({node->left,2*index});
            }
            if(node->right){
                q.push({node->right,2*index+1});
            }
           }
   int width=last-first+1;
        maxwidth=max(maxwidth,width);
        }
        return maxwidth;
     
        
    }
};