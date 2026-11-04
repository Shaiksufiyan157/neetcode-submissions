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
    map<int,int> mp;
    vector<int> rightSideView(TreeNode* root) {
       mp.clear();
      solve(root,0);
      vector<int> res;
      for(auto it:mp){
        res.push_back(it.second);
      }

      return res;
    }

    void solve(TreeNode* root,int level){
        if(!root) return;

        mp[level]=root->val;

        solve(root->left,level+1);
        solve(root->right,level+1);
        
        
    }
};