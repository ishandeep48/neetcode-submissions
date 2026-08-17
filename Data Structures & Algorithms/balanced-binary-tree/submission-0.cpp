class Solution {
public:
    bool balanced = true;
    int getHeight(TreeNode*root){
        if(!balanced) return -1;
        if(!root) return 0;
        int leftHeight = getHeight(root->left);
        int rightHeight =  getHeight(root->right);
        if(abs(leftHeight-rightHeight)>1) balanced= false;
        return 1+max(leftHeight,rightHeight);
    }
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return balanced;
    }
};