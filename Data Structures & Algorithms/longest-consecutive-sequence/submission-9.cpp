class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int size=nums.size();
        if(size==0){
            return 0;
            
        }
        unordered_map<int,int>hmap;
        for(int i:nums){
            hmap[i]++;
        }
        vector<int>isFirst;
        for(int i:nums){
            if(hmap.find(i-1)==hmap.end()){
                isFirst.push_back(i);
            }
        }
        int maxLen=1;
        int count=1;

        for(int i:isFirst){
            bool run=true;
            while(run){
                if(hmap.find(i+1)!=hmap.end()){
                    i++;
                    count++;
                    maxLen=max(maxLen,count);
                }else{
                    
                    count=1;
                    run=!run;
                }
            }
        }
        return maxLen;
    }
};
