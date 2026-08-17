class Solution {
public:
    long long calculateDistance(vector<int>&p1){
        long long x = p1[0]*p1[0];
        long long y = p1[1]*p1[1];
        return x+y;

    }
    struct Comparator{
        bool operator()(pair<vector<int>,int>&p1,pair<vector<int>,int>&p2){
            return p1.second<p2.second;
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<vector<int>,int>,vector<pair<vector<int>,int>>,Comparator> pq;
        for(auto&i:points){
            if(pq.size()<k){
                pq.push({i,calculateDistance(i)});
                continue;
            }else{
                int dist = calculateDistance(i);
                if(dist<pq.top().second){
                    pq.pop();
                    pq.push({i,dist});
                }
            }
        }
        vector<vector<int>>ans;
        while(pq.size()>0){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        return ans;
    }
};