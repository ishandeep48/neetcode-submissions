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
        if (index == nums.size() || sum > goal) {
            return;
        }

        temp.push_back(nums[index]);
        sum += nums[index];
        backtrack(index + 1, nums);
        temp.pop_back();
        sum -= nums[index];
        int temp_index = index;
        while (temp_index<nums.size() && nums[temp_index] == nums[index] ) {
            temp_index++;
        }
        backtrack(temp_index, nums);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        goal = target;
        backtrack(0, candidates);
        return ans;
    }
};