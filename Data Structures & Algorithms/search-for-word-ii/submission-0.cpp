struct TrieNode {
    TrieNode* arr[26];
    bool isEnd = false;
    TrieNode() {
        for (int i = 0; i < 26; i++) {
            arr[i] = nullptr;
        }
    }
};
// struct PairHash {
//     size_t operator()(const pair<int, int>& p) const {
//         return p.first * 31 + p.second;
//     }
// };
class Solution {
public:
    // unordered_set<pair<int, int>, PairHash> visited;
    vector<string> ans;
    string tempString = "";
    TrieNode* root = new TrieNode();
    void buildTrie(string word) {
        TrieNode* temp = root;
        for (const char& i : word) {
            if (temp->arr[i - 'a']) {
                temp = temp->arr[i - 'a'];
            } else {
                temp->arr[i - 'a'] = new TrieNode();
                temp = temp->arr[i - 'a'];
            }
        }
        temp->isEnd = true;
    }
    void backtrack(TrieNode* temp, int i, int j, int m, int n,
                   vector<vector<char>>& board) {
        if (temp->isEnd) {
            ans.push_back(tempString);
            temp->isEnd = false;
        }

        int dr[4] = {-1, 1, 0, 0};
        int dc[4] = {0, 0, -1, 1};

        for (int k = 0; k < 4; k++) {
            int ni = i + dr[k];
            int nj = j + dc[k];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n &&
                board[ni][nj] != '#') {

                if (temp->arr[board[ni][nj] - 'a']) {
                    char ch = board[ni][nj];
                    tempString += board[ni][nj];
                    board[ni][nj] = '#';

                    backtrack(temp->arr[ch - 'a'], ni, nj, m, n, board);

                    board[ni][nj] = ch;
                    tempString.pop_back();
                }
            }
        }
    }
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        for (string& i : words)
            buildTrie(i);
        TrieNode* temp = root;
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (temp->arr[board[i][j] - 'a']) {
                    char ch = board[i][j];

                    tempString += board[i][j];
                    board[i][j] = '#';
                    backtrack(temp->arr[ch - 'a'], i, j, board.size(),
                              board[i].size(), board);
                    board[i][j] = ch;
                    tempString.pop_back();
                }
            }
        }
        return ans;
    }
};