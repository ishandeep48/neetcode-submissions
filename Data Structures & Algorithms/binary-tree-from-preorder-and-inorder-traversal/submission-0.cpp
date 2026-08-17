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
    unordered_map<int, int> mp;
    TreeNode*build(vector<int>&preorder,vector<int>&inorder,int inStart,int inEnd,int &preIndex){
        if((inStart>inEnd)||preIndex>=preorder.size()){
            return nullptr;
        }
        int ind=mp[preorder[preIndex]];
        TreeNode*root=new TreeNode(preorder[preIndex++]);
        root->left=build(preorder,inorder,inStart,ind-1,preIndex);
        root->right=build(preorder,inorder,ind+1,inEnd,preIndex);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int start =0;
        TreeNode*ans=build(preorder,inorder,0,inorder.size()-1,start);
        return ans;
    }
};