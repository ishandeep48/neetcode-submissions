class Solution {
public:

    int minCost(const vector<int>&cost,vector<int>&currCost,int n){
        if(currCost[n]!=-1)return currCost[n];
        if(n<2){
            if(n==0)return cost[0];
            if(n==1)return cost[1];
        }
        int cost1=minCost(cost,currCost,n-1);
        int cost2=minCost(cost,currCost,n-2);
        int cac=cost[n];
        if(cost1<cost2){
            currCost[n]=cac+cost1;
        }else{
            currCost[n]=cac+cost2;
        }

        return currCost[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>currCost(cost.size(),-1);
        return min(minCost(cost,currCost,cost.size()-1),minCost(cost,currCost,cost.size()-2));
    }
};