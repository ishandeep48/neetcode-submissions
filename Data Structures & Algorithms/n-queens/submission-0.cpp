class Solution {
public:
    vector<vector<string>> ans;
    vector<string> temp;
    bool isSafe(int row, int col, int n) {
        for (int i = 0; i < temp.size(); i++) {
            if (temp[i][col] == 'Q') {
                return false;
            } else if (col - (row - i) >= 0 &&
                       temp[i][col - (row - i)] == 'Q') {
                return false;
            } else if (col + (row - i) < n && temp[i][col + (row - i)] == 'Q') {
                return false;
            }
        }
        return true;
    }
    string genString(int n,int i) {
        string tempgen = "";
        for (int q = 0; q < n; q++) {
            if (q == i) {
                tempgen += 'Q';
            } else {
                tempgen += '.';
            }
        }
        return tempgen;
        ;
    }
    void backtrack(int n, int row) {
        if (row == n) {
            ans.push_back(temp);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (isSafe(row, i, n)) {
                string tempgen=genString(n,i);
                temp.push_back(tempgen);
                backtrack(n,row+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        backtrack(n,0);
        return ans;
    }
};