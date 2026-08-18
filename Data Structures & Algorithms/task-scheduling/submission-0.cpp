class Solution {
public:
    struct Comparator {
        bool operator()(pair<char, int>& a, pair<char, int>& b) {
            return a.second < b.second;
        }
    };
    pair<char, int> getMax(unordered_map<char, int>& mp) {
        int maxx = INT_MIN;
        char ch;
        for (auto& i : mp) {
            if (i.second > maxx) {
                maxx = i.second;
                ch = i.first;
            }
        }
        return {ch, maxx};
    }
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> mp;
        for (char i : tasks) {
            mp[i]++;
        }
        pair<char,int>Maxi=getMax(mp);
        int maxFreq = Maxi.second;
        int minRequired = ((maxFreq - 1) * (n + 1)) + 1;

        for(auto&i:mp){
            if(i.first==Maxi.first){
                continue;
            }
            if (i.second == maxFreq) {
                minRequired++;
            }
        }
        return max((int)tasks.size(), minRequired);
    }
};