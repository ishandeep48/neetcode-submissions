class Solution {
public:
    int maxElement(vector<int>&nums){
        int maxEle=0;
        for(int i:nums){
            maxEle=max(maxEle,i);
        }
        return maxEle;
    }
    long long timeToEat(vector<int>&nums , int &speed){
        long long totalTime = 0;
        for( int i : nums ){
            totalTime += (i + speed - 1) / speed;
        }
        return totalTime;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int max_pile = maxElement(piles);
        int start =1;
        int end = max_pile;
        int ans = 0;
        while(start<=end){
            int middle = start + (end - start) / 2;;
            long long TTE=timeToEat(piles,middle);
            if(TTE>h){
                start = middle+1;
            }else{
                ans = middle;
                end = middle-1;
            }
        }
        return ans;
    }
};