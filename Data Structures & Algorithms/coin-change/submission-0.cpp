class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int size = amount;
        // int INT_MAX = INT_MAX-1;
        vector<int> dp(size + 1, INT_MAX-1);
        dp[0] = 0;
        for (int i = 1; i <= size; i++) {
            for (int coin : coins) {
                if (coin <= i)
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
            }
        }
        return dp[size] == INT_MAX-1 ? -1 : dp[size];
    }
};