class Solution {
public:
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(int index, vector<int>& nums) {
        if (index == nums.size()) {
            ans.push_back(temp);
            return;
        }
        temp.push_back(nums[index]);
        backtrack(index+1,nums);
        temp.pop_back();
        int tempind=index;
        while (tempind<nums.size() && nums[tempind]==nums[index]) {
            tempind++;
        }
        backtrack(tempind,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        backtrack(0,nums);
        return ans;
    }
};