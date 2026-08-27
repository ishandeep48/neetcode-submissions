class Solution {
public:
    unordered_set<int> visited;
    vector<vector<int>> ans;
    vector<int> temp;
    void backtrack(vector<int>& nums) {
        if (temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        };
        for(int i=0;i<nums.size();i++){
            if(visited.count(nums[i]))continue;
            visited.insert(nums[i]);
            temp.push_back(nums[i]);
            backtrack(nums);
            temp.pop_back();
            visited.erase(nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        backtrack(nums);
        return ans;
    }
};