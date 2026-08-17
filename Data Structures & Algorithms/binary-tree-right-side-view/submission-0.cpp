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
    vector<int> rightSideView(TreeNode* root) {
        if(!root) return {};
        vector<int>ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int last_ele=-101;
            int size= q.size();
            for(int i=0;i<size;i++){
                    if(q.front()->left){
                        q.push(q.front()->left);
                    }
                    if(q.front()->right){
                        q.push(q.front()->right);
                    }
                    last_ele=q.front()->val;
                    q.pop();
            }
            if(last_ele!=-101)ans.push_back(last_ele);
        }
        return ans;
    }
};