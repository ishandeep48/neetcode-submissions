class Solution {
public:
    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
        }
    };
    unordered_map<char, vector<pair<int, int>>> coords;
    unordered_set<pair<int, int>, pairHash> visited;
    bool isCompleted = false;
    // string temp = "";
    bool is4Neighbor(pair<int, int>& posi1, pair<int, int>& posi2) {
        return (abs(posi1.first - posi2.first) +
                abs(posi1.second - posi2.second)) == 1;
    }
    void backtrack(pair<int, int>& lastPosi, int index, string& word) {
        if (index == word.size()) {
            isCompleted = true;
            return;
        }
        vector<pair<int, int>> pos = coords[word[index]];

        for (auto& i : pos) {
            if (is4Neighbor(lastPosi, i) && !visited.count(i)) {
                // temp += word[index];
                visited.insert(i);
                backtrack(i, index + 1, word);
                if (isCompleted)
                    return;
                visited.erase(i);
                // temp.pop_back();
            }
        }
    }
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                coords[board[i][j]].push_back({i, j});
            }
        }
        for (char i : word) {
            if (!coords.count(i)) {
                return false;
            }
        }
        vector<pair<int, int>> pos = coords[word[0]];

        int index = 1;
        for (auto& i : pos) {
            // temp += word[0];
            visited.insert(i);
            pair<int, int> lastPosi = i;
            backtrack(lastPosi, index, word);
            if (isCompleted)
                return true;
            visited.erase(i);
            // temp.pop_back();
        }
        return false;
    }
};