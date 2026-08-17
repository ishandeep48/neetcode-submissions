class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit =0;
        int i=0;
        int j=1;
        while(i<prices.size() &&j<prices.size()){
            int profit = prices[j]-prices[i];
            if(profit<0){
                i=j;
                j++;
            }else{
                maxProfit = max(maxProfit,profit);
                j++;
            }
        }
        return maxProfit;
    }
};
