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
    unordered_map<int,int> mp;
    TreeNode* solve(int l,int r,vector<int>& preorder, vector<int>& inorder,int n,int &i){
        if(l>r) return NULL;
        int index=mp[preorder[i++]];
        TreeNode* node = new TreeNode(inorder[index]);
        node->left=solve(l,index-1,preorder,inorder,n,i);
        node->right=solve(index+1,r,preorder,inorder,n,i);

        return node;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int i=0;
        return solve(0,n-1,preorder,inorder,n,i);
    }
};