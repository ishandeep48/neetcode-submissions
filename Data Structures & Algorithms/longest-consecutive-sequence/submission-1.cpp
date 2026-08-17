class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0){
            return 0;
        }
        vector<int>isFirst;
        unordered_map<int,int>hmap;
        for(int i:nums){
            hmap[i]++;
        }
        for(int i:nums){
            if(!hmap.count(i-1)){
                isFirst.push_back(i);
            }
        }
        vector<int>res;
        for(int i=0;i<isFirst.size();i++){
            bool run = true;
            int itr=1;
            int count=1;
            while (run){
                if(hmap.count(isFirst[i]+itr)){
                    count++;
                    itr++;
                }else{
                    run=!run;
                }
            }
            res.push_back(count);
        }
        int maxx =  *max_element(res.begin(),res.end());
        return maxx;
    }
};
