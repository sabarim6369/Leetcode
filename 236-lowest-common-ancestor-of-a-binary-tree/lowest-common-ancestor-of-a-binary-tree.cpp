/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool findpath(vector<TreeNode*>& v1, TreeNode* root, TreeNode* target) {
        if (!root)
            return false;
        v1.push_back(root);
        if (root == target)
            return true;
        if (findpath(v1, root->left, target) ||
            findpath(v1, root->right, target)) {
            return true;
        }
        v1.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1;
        vector<TreeNode*> v2;
        TreeNode* curr1 = root;
        TreeNode* curr2 = root;
        findpath(v1, curr1, p);
        findpath(v2, curr2, q);
        
        int n1 = v1.size();
        int n2 = v2.size();
         for(auto a:v1){
            cout<<a->val<<"->";
         }
         cout<<endl;
          for(auto a:v2){
            cout<<a->val<<"->";

         }
        
         TreeNode* ans=nullptr;
         int i=0,j=0;
         while(i<n1 && j<n2 && v1[i]==v2[j]){
            ans=v1[i];
            i++;
            j++;
         }

          
         return ans;
    }
};