class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> hset;
        unordered_set<char> hset1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.') {
                    if (hset.count(board[i][j]))
                        return false;
                    hset.insert(board[i][j]);
                }

                if (board[j][i] != '.') {
                    if (hset1.count(board[j][i]))
                        return false;
                    hset1.insert(board[j][i]);
                }
            }
            hset.clear();
            hset1.clear();
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                int sub_x = i * 3;
                int sub_y = j * 3;
                for (int small_x = sub_x; small_x < sub_x + 3; small_x++) {
                    for (int small_y = sub_y; small_y < sub_y + 3; small_y++) {
                        if (board[small_x][small_y] != '.') {
                            if (hset.count(board[small_x][small_y])) {
                                return false;
                            }
                            hset.insert(board[small_x][small_y]);
                        }
                    }
                }
                hset.clear();
            }
        }
        return true;
    }
};