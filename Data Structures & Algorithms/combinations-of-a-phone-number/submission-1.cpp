class Solution {
public:
    vector<string> ans;
    string temp="";
    vector<vector<char>>keypad={
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'},
    };
    void backtrack(string&s,int posi){
        if(posi == s.size()){
            ans.push_back(temp);
            return;
        }
        int index = (int)s[posi]-'2';
        for(int i=0;i<keypad[index].size();i++){
            temp+=keypad[index][i];
            backtrack(s,posi+1);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits=="")return {};
        backtrack(digits,0);
        return ans;
    }
};