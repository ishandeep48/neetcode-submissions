class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int size = board.size();
        int innerSize = board[0].size();
        queue<pair<int, int>> q;

        // capture all the starting points
        for (int i = 0; i < size; i++) {
            if (i == 0 || i == size - 1) {
                for (int j = 0; j < innerSize; j++) {
                    if (board[i][j] == 'O') {
                        board[i][j]='Z';
                        q.push({i, j});
                    }
                }
            } else {
                if (board[i][0] == 'O') {
                    board[i][0]='Z';
                    q.push({i, 0});
                }
                if (board[i][innerSize - 1] == 'O') {
                    board[i][innerSize - 1]='Z';
                    q.push({i, innerSize - 1});
                }
            }
        }
        int xC[4] = {0, 1, 0, -1};
        int yC[4] = {1, 0, -1, 0};
        while (!q.empty()) {
            pair<int, int> temp = q.front();
            q.pop();
            // board[temp.first][temp.second] = 'Z';
            for (int i = 0; i < 4; i++) {
                int newX = temp.first + xC[i];
                int newY = temp.second + yC[i];
                if ((newX > -1 && newX < size) &&
                    (newY > -1 && newY < innerSize)) {
                    if (board[newX][newY] == 'O') {
                        board[newX][newY]='Z';
                        q.push({newX, newY});
                    }
                }
            }
        }

        // Convert all O to X and Z to O

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < innerSize; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                } if (board[i][j] == 'Z') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};