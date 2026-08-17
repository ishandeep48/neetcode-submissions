/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root)
            return "";
        string ans = "";
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* temp = q.front();
            q.pop();

            if (temp == nullptr) {
                ans += "#;";
                continue;
            }

            ans += to_string(temp->val) + ";";

            q.push(temp->left);
            q.push(temp->right);
        }
        cout << ans << endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if (data == "")
            return nullptr;

        stringstream ss(data);
        string value;

        getline(ss, value, ';');
        TreeNode* root = new TreeNode(stoi(value));

        queue<TreeNode*> q;
        q.push(root);

        int height = 0;

        while (!q.empty()) {
            int nodes = pow(2, height);

            for (int i = 0; i < nodes && !q.empty(); i++) {
                TreeNode* curr = q.front();
                q.pop();

                if (getline(ss, value, ';')) {
                    if (value != "#") {
                        curr->left = new TreeNode(stoi(value));
                        q.push(curr->left);
                    }
                }

                if (getline(ss, value, ';')) {
                    if (value != "#") {
                        curr->right = new TreeNode(stoi(value));
                        q.push(curr->right);
                    }
                }
            }

            height++;
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));