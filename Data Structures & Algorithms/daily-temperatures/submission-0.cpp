class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>>stk;
        // unordered_map<int,int>hmap;
        int size=temperatures.size();
        vector<int>ans(size);
        for( int i = size - 1;i>=0;i--){
            int cur_temp = temperatures[i];
            if( i == size -1){
                ans[i]=0;
                stk.push({cur_temp,i});
                continue;
            }
            if(stk.top().first>cur_temp){
                ans[i] = stk.top().second - i;
                stk.push({cur_temp,i});
            }else{
                while(!stk.empty() && stk.top().first<=cur_temp){
                    stk.pop();
                }
                if(stk.empty()){
                    ans[i] = 0;
                }else{
                    ans[i] = stk.top().second - i;
                }
                stk.push({cur_temp,i});
            }
        }
        return ans;
    }
};