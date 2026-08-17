class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        int win_size = s1.size();
        vector<int> arr(26, 0);
        vector<int> arr2(26, 0);
        for (char chS1 : s1) {
            arr[chS1-'a']++;
        }
        for (int k = 0; k < win_size; k++) {
            arr2[s2[k]-'a']++;
        }
        int i = 0;
        int j = win_size - 1;
        while (j < s2.size()) {
            if (arr == arr2) {
                return true;
            }
            arr2[s2[i]-'a']--;i++;
            j++;
            if (j < s2.size()) {
                arr2[s2[j]-'a']++;
            }
        }
        return false;
    }
};