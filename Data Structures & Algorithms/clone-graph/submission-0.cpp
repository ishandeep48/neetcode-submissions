/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_map<int, Node*> visited;
        Node* orgTemp = node;
        if (!orgTemp) {
            return nullptr;
        }
        Node* dcNode = new Node(orgTemp->val);
        visited[orgTemp->val] = dcNode;
        queue<Node*> q;
        Node* temp = dcNode;
        q.push(orgTemp);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                Node* ntemp = q.front();
                q.pop();
                Node* toUse = visited[ntemp->val];
                for (auto neigh : ntemp->neighbors) {
                    if (visited.count(neigh->val)) {
                        toUse->neighbors.push_back(visited[neigh->val]);
                    } else {
                        Node* new_node = new Node(neigh->val);
                        toUse->neighbors.push_back(new_node);
                        visited[neigh->val] = new_node;
                        q.push(neigh);
                    }
                    
                }
            }
        }
        return dcNode;
    }
};