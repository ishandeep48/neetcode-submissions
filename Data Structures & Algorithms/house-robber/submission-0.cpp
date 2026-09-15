class Solution {
public:
    int totalStolen(const vector<int>& nums, vector<int>& steal, int n) {
        if (n < 0)
            return 0;
        if (steal[n] != -1)
            return steal[n];

        steal[n] = max(totalStolen(nums, steal, n - 1),
                       totalStolen(nums, steal, n - 2) + nums[n]);

        return steal[n];
    }
    int rob(vector<int>& nums) {

        vector<int> steal(nums.size(), -1);
        return totalStolen(nums, steal, nums.size() - 1);
                   
    }
};