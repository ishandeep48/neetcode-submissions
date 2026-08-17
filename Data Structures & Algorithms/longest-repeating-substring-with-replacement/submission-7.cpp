class Solution {
public:
    int getMaxLength(unordered_map<char,int>&hmap){
        int maxLength=0;
        for(auto&p:hmap){
            maxLength = max(maxLength,p.second);
        }
        return maxLength;
    }
    int characterReplacement(string s, int k) {
        int i=0;
        int j=i;
        int maxLength=0;
        unordered_map<char,int>hmap;
        while(j<s.length()){
            hmap[s[j]]++;
            int maxFreq = getMaxLength(hmap);
            int window_size = j-i+1;
            if(window_size - maxFreq <=k){
                maxLength = max(maxLength , window_size);
                j++;
            }else{
                
                hmap[s[i++]]--;
                // i++;
                hmap[s[j]]--;
            }
        }
        return maxLength;
    }
};
