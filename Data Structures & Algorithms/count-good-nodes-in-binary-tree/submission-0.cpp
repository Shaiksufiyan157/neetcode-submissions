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
    int totalGoodNodes;
    int goodNodes(TreeNode* root) {
        totalGoodNodes=0;
        solve(root,root->val);
        return totalGoodNodes;
    }

    void solve(TreeNode* root,int maxi){
        if(!root) return;

        if(root->val>=maxi) totalGoodNodes++;
        maxi=max(root->val,maxi);
        solve(root->left,maxi);
        solve(root->right,maxi);
    }
};