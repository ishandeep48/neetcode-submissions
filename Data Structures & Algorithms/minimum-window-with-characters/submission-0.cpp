class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> needMap;
        for (char i : t)
            needMap[i]++;
        unordered_map<char, int> currentMap;
        string ans = "";
        int i, j, formed, required, min_len, start;
        i = j = start = formed = 0;
        min_len = INT_MAX;
        required = needMap.size();
        while (j < s.size() && needMap.count(s[j]) == 0) {
            j++;
        }
        if (j == s.size()) {
            return "";
        }
        currentMap[s[j]]++;
        if (currentMap[s[j]] == needMap[s[j]]) {
            formed++;
            if(formed == required){
                ans+=s[j];
                return ans;
            }
        }
        i = start = j;
        j++;
        // if(j=s.size()){
            
        // }
        while (j < s.size()) {
            if (needMap.count(s[j]) == 0) {
                j++;
                continue;
            }
            char c = s[j];
            currentMap[c]++;
            if (needMap[c] == currentMap[c]) {
                formed++;
            }
            while (formed == required) {
                if (j - i + 1 < min_len) {
                    min_len = j - i + 1;
                    start = i;
                }
                char rem = s[i];
                currentMap[rem]--;

                if (needMap.count(rem) && currentMap[rem] < needMap[rem]) {
                    formed--;
                }
                i++;
                while (i<s.size() && needMap.count(s[i]) == 0) {
                    i++;
                }
            }
            j++;
        }
        ans = min_len == INT_MAX ? "" : s.substr(start, min_len);
        return ans;
    }
};