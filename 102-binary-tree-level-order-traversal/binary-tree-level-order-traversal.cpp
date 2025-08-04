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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*>q;
                vector<vector<int>> result;

        if(!root)return {};
        q.push(root);
        while(!q.empty()){
            int qsize=q.size();
            vector<int>inner;
            for(int i=0;i<qsize;i++){
                TreeNode *curr=q.front();
                q.pop();
                inner.push_back(curr->val);
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
            }
            result.push_back(inner);
        }
        return result;
    }
};