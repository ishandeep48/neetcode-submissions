class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (int i : nums)
            sum += i;
        if (sum % 2 != 0)
            return false;
        sum /= 2;
        int size = nums.size();
        vector<vector<bool>> dp(size + 1, vector<bool>(sum + 1, false));
        for (int i = 0; i <= size; i++)
            dp[i][0] = true;

        for (int i = 1; i <= size; i++) {
            for (int j = 1; j <= sum; j++) {
                if (j < nums[i - 1]) {
                    dp[i][j] = dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
                }
            }
        }
        return dp[size][sum];
    }
};