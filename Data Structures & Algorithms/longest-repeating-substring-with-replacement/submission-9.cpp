class Solution {
public:
    int characterReplacement(string s, int k) {
        int i,j;
        i=j=0;
        int max_freq=0;
        int ans =0;
        unordered_map<char,int>hmap;
        while(j<s.length()){
            hmap[s[j]]++;
            max_freq = max(max_freq , hmap[s[j]]);
            int win_size = j-i+1;
            int replacement_needed = win_size-max_freq;
            if(replacement_needed>k){
                hmap[s[i]]--;
                i++;
                
                
            }
            ans = max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};