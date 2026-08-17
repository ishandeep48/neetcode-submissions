class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int N = nums.size();
        unordered_map<int,int>hmap;
        for(int &i:nums){
            hmap[i]++;
        }
        vector<vector<int>>buckets(N);
        vector<int>res(k);
        for(auto&p:hmap){
            buckets[p.second-1].push_back(p.first);
        }
        int count=0;
        int i=N-1;
        int res_itr=0;
        while(count<k && i>=0){
            if(!buckets[i].empty()){
                int cur_size = buckets[i].size();
                int min_itr = min(cur_size,k);
                for(int j=0;j<min_itr;j++){
                    res[res_itr]=buckets[i][j];
                    count++;
                    res_itr++;
                }
            }
            i--;
        }
        return res;
    } 
};
