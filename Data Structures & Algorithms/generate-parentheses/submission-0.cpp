class Solution {
public:
    int open = 0;
    int close = 0;
    vector<string> ans;
    string temp = "";
    void backtrack(int target) {
        if ((close == target) && (open == target)) {
            ans.push_back(temp);
            return;
        }
        if (open < target) {
            temp += '(';
            open++;
            backtrack(target);
            temp.pop_back();
            open--;
        }

        if (close < open) {
            close++;
            temp += ')';
            backtrack(target);
            temp.pop_back();
            close--;
        }
    }
    vector<string> generateParenthesis(int n) {
        backtrack(n);
        return ans;
    }
};