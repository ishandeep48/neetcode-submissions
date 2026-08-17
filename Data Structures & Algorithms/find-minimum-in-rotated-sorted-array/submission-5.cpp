class Solution {
public:
    int findMin(vector<int> &nums) {
        int start=0;
        int end=nums.size()-1;
        if(nums[start]<nums[end]) return nums[start];
        int minnum=999999999;
        while(start<=end){
            int mid = (start+end)/2;
            if(nums[mid]<=minnum){
                minnum=nums[mid];
            }
            if(nums[mid]>nums[end]){
                start=mid+1;
            }else if(nums[mid]<=nums[end]){
                end=mid-1;
            }
        }
        return minnum;
    }
};
