class Solution {
public:
    int stealN(const vector<int>& nums, vector<int>& steal, int n,
               bool includeFirst) {
        if (includeFirst) {
            if (n < 0)
                return 0;
        } else {
            if (n < 1)
                return 0;
        }
        if (steal[n] != -1)
            return steal[n];

        steal[n] = max(stealN(nums, steal, n - 1, includeFirst),
                       stealN(nums, steal, n - 2, includeFirst) + nums[n]);
        return steal[n];
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return nums[0];
        vector<int> steal(n, -1);
        int noF=stealN(nums, steal, n - 2, true);
        steal.assign(n,-1);
        int noL=stealN(nums, steal, n - 1, false);
        return max(noF,noL);
    }
};