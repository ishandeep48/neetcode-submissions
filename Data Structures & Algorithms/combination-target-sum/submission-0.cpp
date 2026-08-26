class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    int sum = 0;
    int goal = 0;
    void backtrack(int index, vector<int>& nums) {
        if (sum == goal) {
            ans.push_back(temp);
            return;
        }
        if (sum > goal || index == nums.size()) {
            return;
        }
        temp.push_back(nums[index]);
        sum += nums[index];
        backtrack(index, nums);
        temp.pop_back();
        sum -= nums[index];
        backtrack(index + 1, nums);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        goal = target;
        backtrack(0, candidates);
        return ans;
    }
};