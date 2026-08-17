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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        queue<TreeNode*>q;
        q.push(root);
        // ans.push({root->val});
        while(!q.empty()){
            int size = q.size();
            vector<int>tempans;
            for (int i=0;i<size;i++){
                if(!q.front()){
                    q.pop();
                    continue;
                }
                tempans.push_back(q.front()->val);
                q.push(q.front()->left);
                q.push(q.front()->right);
                q.pop();
            }

            if(tempans.size()>0)ans.push_back(tempans);
        }
        return ans;
    }
};