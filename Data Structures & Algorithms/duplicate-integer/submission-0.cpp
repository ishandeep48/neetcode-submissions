class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int,int> hmap;
        for(int i:nums){
            if(hmap.count(i) == 0){
                hmap[i]=1;
            }else{
                return true;
            }
        }
        return false;
    }
};