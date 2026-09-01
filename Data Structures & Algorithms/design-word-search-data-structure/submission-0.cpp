struct TrieNode {
    TrieNode* arr[26];
    bool isEnd = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
    }
};
class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }

    void addWord(string word) {
        TrieNode* temp = root;
        for (char& i : word) {
            if (temp->arr[i - 'a']) {
                temp = temp->arr[i - 'a'];
            } else {
                temp->arr[i - 'a'] = new TrieNode();
                temp = temp->arr[i - 'a'];
            }
        }
        temp->isEnd = true;
    }

    bool search(const string&word, int index = 0, TrieNode* temp = nullptr) {
        if (!temp)
            temp = root;
        if (index == word.length()) {
            return temp->isEnd;
        }
        // base case
        if (word[index] == '.') {
            for (int i = 0; i < 26; i++) {
                if (temp->arr[i] && search(word, index + 1, temp->arr[i])) {
                    return true;
                }
            }
            return false;
        } else {
            if (temp->arr[word[index] - 'a']) {
                // if (index + 1 == word.length()) {
                //     return temp->arr[word[index] - 'a']->isEnd;
                // } else {
                return search(word, index + 1, temp->arr[word[index] - 'a']);
                // }
            } else {
                return false;
            }
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */