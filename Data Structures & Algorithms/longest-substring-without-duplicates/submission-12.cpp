class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;
        int j=0;
        int size = s.length();
        unordered_map<char,int>hmap;
        int maxCount =0;
        while(j<size){
            if(hmap.count(s[j]) && hmap[s[j]]>=i){
                i=hmap[s[j]]+1;

            }
            hmap[s[j]]=j;
            maxCount= max(maxCount,j-i+1);
            j++;
        }
        return maxCount;
    }
};
