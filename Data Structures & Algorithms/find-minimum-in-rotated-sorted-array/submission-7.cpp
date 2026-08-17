class Solution {
public:
    int findMin(vector<int>& nums) {
        int start =0;
        int end = nums.size()-1;
        while(start<end){
            int middle = start + (end-start)/2;
            if(nums[middle]>nums[end]){
                start = middle+1;
            }else{
                end = middle;
            }
        }
        return nums[start];
    }
};