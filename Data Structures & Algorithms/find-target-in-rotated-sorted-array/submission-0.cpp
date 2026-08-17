class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start =0;
        int end = nums.size()-1;
        while(start<=end){
            int middle = start + (end-start )/2;
            if(nums[middle] == target){
                return middle;
            }
            if(nums[middle]<=nums[end]){
                // right is sorted
                if(target>nums[middle] && target<=nums[end]){
                    start=middle+1;
                }else{
                    end = middle-1;
                }
            }else if(nums[middle]>=nums[start]){
                //left is sorted
                if(target<nums[middle] && target>=nums[start]){
                    end = middle - 1;
                }else{
                    start = middle+1;
                }
            }
        }
        return -1;
    }
};