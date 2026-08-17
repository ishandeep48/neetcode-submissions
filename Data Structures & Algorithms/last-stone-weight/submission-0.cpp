class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()<2){
            return stones[0];
        }
        priority_queue<int,vector<int>,less<>> pq;
        for(int i:stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int y=pq.top();
            pq.pop();
            int x=pq.top();
            pq.pop();
            if(x!=y){
                int ins=y-x;
                pq.push(ins);
            }
        }
        if(pq.size()==0) return 0;
        return pq.top();
    }
};