class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> smap;
        unordered_map<char,int>tmap;
        for(char i:s){
            smap[i]++;
        }
        for(char i:t){
            tmap[i]++;
        }

        if(smap == tmap){
            return true;
        }else{
            return false;
        }
    }
};
