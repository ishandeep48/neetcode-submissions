class Solution {
public:
vector<vector<int>>ans;
vector<int>temp;
void backtrack(int index,vector<int>&nums){
    if(index == nums.size()){
        ans.push_back(temp);
        return;
    }
    temp.push_back(nums[index]);
    backtrack(index+1,nums);
    temp.pop_back();
    backtrack(index+1,nums);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        backtrack(0,nums);
        return ans;
    }
};
