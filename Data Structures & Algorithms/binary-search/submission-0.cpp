class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0 ;
        int end = nums.size()-1;
        while(start<=end){
            int middle = (start+end)/2;
            if(nums[middle]==target){
                return middle;
            }if(nums[middle]>target){
                end=middle-1;
            }else{
                start = middle+1;
            }
        }
        return -1;
    }
};