class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>hmap;
        vector<int>res(2);
        for(int i:nums){
            hmap[i]++;
        }
        for(int i=0;i<nums.size();i++){
            int rem = target - nums[i];
            if(hmap.count(rem)){
                res[0]=i;
                for(int j=i+1;j<nums.size();j++){
                    if(nums[j] == rem){
                        res[1]=j;
                        return res;
                    }
                }
            }
        }
        return res;
    }
};
