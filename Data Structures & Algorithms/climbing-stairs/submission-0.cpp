class Solution {
public:
    int climbStairs(int n) {
        if(n<=3)return n;
        vector<int>dp;
        dp.insert(dp.end(),{1,2,3});
        for(int i=3;i<n;i++){
            dp.push_back(dp[i-1]+dp[i-2]);
        }
        return dp[n-1];
    }
};