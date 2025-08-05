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
 //iterative traversal
 //keep one curr and point it to root,untill currbecoming null move curr to left and each vallue to be pushed to stack
 //if curr become null pop one from stack and print it and move to its right
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>ans;
        TreeNode* curr=root;
        stack<TreeNode*>stk;
        while(curr!=nullptr ||!stk.empty()){
            while(curr!=nullptr){
                stk.push(curr);
                curr=curr->left;
            }
            curr=stk.top();
            stk.pop();
            ans.push_back(curr->val);
            curr=curr->right;
        }
        return ans;
    }
};