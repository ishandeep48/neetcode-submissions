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
    void inOrder(TreeNode* root, int& ans, int& count, int k) {
        if (!root)
            return;
        if (count >= k)
            return;
        inOrder(root->left, ans, count, k);
        if (count < k) {
            ans = root->val;
            count++;
        }
        inOrder(root->right, ans, count, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        int ans = 0;
        int count = 0;
        inOrder(root, ans, count, k);
        return ans;
    }
};