class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) return 0;
        int i=0;
        int j=i;
        int maxStr=0;
        unordered_map<char,int>hmap;
        // hmap[s[j]] = j;
        // j++;
        while(j<s.length()){
            if(hmap.count(s[j]) && hmap[s[j]]>=i){
                i=hmap[s[j]]+1;

            }
            hmap[s[j]]=j;
            maxStr = max(maxStr,j-i+1);
            j++;
        }
        return maxStr;
    }
};
