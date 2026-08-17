class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>hmap;
        for(string i:strs){
            string sorted = i;
            sort(sorted.begin(),sorted.end());
            hmap[sorted].push_back(i);
        }
        vector<vector<string>>res;
        for(auto&p:hmap){
            res.push_back(p.second);
        }
        return res;
    }
};
