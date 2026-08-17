class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int size = nums.size();
        if(k>size) return {};
        vector<int>ans;
        priority_queue<pair<int,int>,vector<pair<int,int>>,less<>>pq;
        int i=0;
        int j=0;
        for( ; j<k;j++){
            pq.push({nums[j],j});
        }
        ans.push_back(pq.top().first);
        if(j==size) return ans;
        while(j<size){
            i++;
            while(!pq.empty() && pq.top().second<i){
                pq.pop();
            }
            pq.push({nums[j],j});
            j++;
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};