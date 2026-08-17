class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        for(int i=0;i<nums.size() && nums[i]<=0;i++){
            if(i>0 and nums[i-1]==nums[i]){
                continue;
            }
            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    //push to result;
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[k+1]==nums[k]) k--;
                    while(j<k && nums[j-1]==nums[j]) j++;
                    
                }else if(nums[i]+nums[j]+nums[k]>0){
                    // k--;
                    while(nums[k-1]==nums[k]) k--;
                    k--;
                }else{
                    while(nums[j+1]==nums[j]) j++;
                    j++;
                }
            }
        }
        return res;
    }
};
