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
 
// class Solution {
// public: 
//    int helper(vector<int>&currlevelsum,int index){
//     if(index>=currlevelsum.size()){
//     return 0;    
//     }
//     int take=currlevelsum[index]+helper(currlevelsum,index+2);
//     int nottake=helper(currlevelsum,index+1);
//     return max(take,nottake);


//    }
//     int rob(TreeNode* root) {
//         vector<int>ans;
//         queue<TreeNode*>q;
//        if(!root){
//         return 0;
//        }
//        q.push(root);
//        while(!q.empty()){
//         int size=q.size();
//         int currsum=0;
//         for(int i=0;i<size;i++){
//             TreeNode *curr=q.front();
//             currsum+=curr->val;
//             q.pop();
//             if(curr->left){
//                 q.push(curr->left);
//             }
//             if(curr->right){
//                 q.push(curr->right);
//             }

//         }
//         ans.push_back(currsum);
//        }
//           vector<vector<int>>dp()

//      return helper(ans,0);
//     }
// };
class Solution {
public:
    pair<int,int> dfs(TreeNode *root){
        if(!root){
            return {0,0};
        }
       auto left=dfs(root->left);
       auto right=dfs(root->right);
        int take=root->val+left.second+right.second;
        int nottake=max(left.first,left.second)+max(right.first,right.second);
        return {take,nottake};
        
    }
    int rob(TreeNode* root) {
        TreeNode *curr=root;
        auto ans= dfs(curr);
       return max(ans.first,ans.second);
    }
};