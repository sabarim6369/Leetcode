/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    map<int, map<int, multiset<int>>> mainset;
    queue<tuple<TreeNode*, int, int>> q;
    void levelorder(TreeNode* node) {
        if (!node)
            return;
        q.push({node, 0, 0});
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                auto [currnode, x, y] = q.front();
                mainset[x][y].insert(currnode->val);
                q.pop();
                if (currnode->left) {
                    q.push({currnode->left, x - 1, y + 1});
                }
                if (currnode->right) {
                    q.push({currnode->right, x + 1, y + 1});
                }
            }
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        levelorder(root);
        for(auto[level,ymap]:mainset){
              cout<<"x "<<level;
              vector<int>vc;
            for(auto[y,setdata]:ymap){
               for(auto a:setdata){
                vc.push_back(a);
               }
              
            }
            ans.push_back(vc);
            
        }
      

        return ans;
    }
};