struct TrieNode {
    TrieNode* arr[26];
    bool isEnd = false;
    TrieNode() {
        for (int a = 0; a < 26; a++) {
            arr[a] = nullptr;
        }
    }
};
class PrefixTree {
public:
    TrieNode* root;

    PrefixTree() {
        root = new TrieNode;
        for (int i = 0; i < 26; i++) {
            root->arr[i] = nullptr;
        }
    }
    
   void insert(string word) {
        TrieNode* temp = root;
        for (char& i : word) {
            if (temp->arr[i - 'a']) {
                temp = temp->arr[i - 'a'];
            } else {
                temp->arr[i - 'a'] = new TrieNode;
                temp = temp->arr[i - 'a'];
            }
        }
        temp->isEnd=true;
    }

    bool search(string word) {
        TrieNode* temp = root;
        for (char& i : word) {
            if (temp->arr[i - 'a']) {
                temp = temp->arr[i - 'a'];
            } else {
                return false;
            }
        }
        return temp->isEnd;
    }

    bool startsWith(string prefix) {
        TrieNode* temp = root;
        for (char& i : prefix) {
            if (temp->arr[i - 'a']) {
                temp = temp->arr[i - 'a'];
            } else {
                return false;
            }
        }
        return true;
    }
};
