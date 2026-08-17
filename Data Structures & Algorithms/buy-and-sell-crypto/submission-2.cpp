class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxMoni = 0;
        int buy=0;
        for(int i=buy+1;i<prices.size();i++){
            if(prices[i]-prices[buy]>0){
                maxMoni = max(maxMoni,prices[i]-prices[buy]);
            }else{
                buy=i;
            }
        }
        return maxMoni;
    }
};
