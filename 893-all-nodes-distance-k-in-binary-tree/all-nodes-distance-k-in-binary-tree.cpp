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
    set<int> ans;
    int levels=0;

   bool findpath(TreeNode* root, TreeNode* target, stack<pair<TreeNode*, int>>& stk, int level = 0) {
    if (!root) return false;

    stk.push({root, level});

    if (root == target) {
        levels=level;
        return true;
    }

    bool left = findpath(root->left, target, stk, level + 1);
    bool right = findpath(root->right, target, stk, level + 1);

    if (left || right) {
        return true;
    }

    stk.pop(); 
    return false;
}


    void findkthelement(TreeNode* root, int k,TreeNode *blocker=nullptr) {
        if (!root||blocker==root)
            return;
        if (k==0) {
            ans.insert(root->val);
            return;
        }
        findkthelement(root->left, k-1 ,blocker);
        findkthelement(root->right, k-1,blocker);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        TreeNode* curr = root;
        stack<pair<TreeNode*, int>>stk;
        findpath(curr, target, stk);
        findkthelement(target,k);
        cout<<levels<<endl;
        TreeNode *block=target;
        while(!stk.empty()){
            auto [curr,level]=stk.top();
            stk.pop();
            cout<<curr->val<<"->"<<level<<endl;
            int needed=abs(levels-level);
            if(needed==k){
                ans.insert(curr->val);
            }
            if(needed<k){
                findkthelement(curr,k-needed,block);
            }
            block=curr;
        }
        return vector<int>(ans.begin(),ans.end());
    }
};
