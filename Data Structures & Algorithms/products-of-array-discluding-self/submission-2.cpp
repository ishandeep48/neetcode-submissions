class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int>forward(size,1);
        vector<int>backward(size,1);

        for(int i=1;i<size;i++){
            forward[i]=forward[i-1]*nums[i-1];
            backward[size-i-1]=backward[size-i]*nums[size-i];
            // forward[size-i-1]=forward[size-i]*nums[size-i-1];
        }
        for(int i=0;i<size;i++){
            forward[i]*=backward[i];
        }
        backward.clear();
        return forward;
    }
};
