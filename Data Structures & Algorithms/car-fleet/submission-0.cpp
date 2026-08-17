class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,double>>posiTime;
        for( int i =0;i<speed.size() ; i++ ){
            posiTime.push_back({position[i],(double)(target-position[i])/speed[i]});
        }
        stack<double>stk;
        int ans=0;
        sort(posiTime.begin(),posiTime.end());
        for( int i = posiTime.size()-1 ; i>=0;i--){
            if(stk.empty()){
                ans++;
                stk.push(posiTime[i].second);
                continue;
            }
            if(posiTime[i].second>stk.top()){
                ans++;
                stk.push(posiTime[i].second);
            }
        }
        return ans;
    }
};