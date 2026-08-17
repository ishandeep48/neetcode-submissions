class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxCount=0;
        string temp_res="";
        for(int i=0;i<s.size();i++){
            
            if(temp_res.find(s[i]) == string::npos){
                temp_res+=s[i];
            }else{
                maxCount=max(maxCount,(int)temp_res.size());
                size_t pos = temp_res.find(s[i]);
                temp_res.erase(0,pos+1);
                
                temp_res+=s[i];
            }
        }
        maxCount=max(maxCount,(int)temp_res.size());
        return maxCount;
    }
};
