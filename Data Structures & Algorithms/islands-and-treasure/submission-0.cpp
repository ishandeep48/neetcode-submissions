class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<pair<int, int>> q;

        // Put all treasure chests into the queue
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int xC[4] = {0, 1, 0, -1};
        int yC[4] = {1, 0, -1, 0};

        while (!q.empty()) {

            auto [x, y] = q.front();
            q.pop();

            for (int i = 0; i < 4; i++) {

                int newX = x + xC[i];
                int newY = y + yC[i];

                if (newX >= 0 && newX < m &&
                    newY >= 0 && newY < n) {

                    // Only process untouched land
                    if (grid[newX][newY] == 2147483647) {

                        grid[newX][newY] = grid[x][y] + 1;

                        q.push({newX, newY});
                    }
                }
            }
        }
    }
};