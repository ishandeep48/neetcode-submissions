class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        int nums_size =nums.size();
        for(int i=0;i<nums_size && nums[i]<=0;i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int j=i+1;
            int k=nums_size-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    res.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while(j<k && nums[j]==nums[j-1]) j++;
                    while(j<k && nums[k] == nums[k+1]) k--; 
                }
                if(nums[j]+nums[k]+nums[i]>0){
                    while(nums[k-1]==nums[k]){
                        k--;
                    
                    }
                    k--;
                }
                if(nums[j]+nums[k]+nums[i]<0){
                    while(nums[j+1]==nums[j]){
                        j++;
                    }
                    j++;
                }
            }
        }
        return res;
    }
};
