class Solution {
public:
    vector<vector<string>> ans;
    vector<string>temp;
    bool isPalindrome(string&s,int start,int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    void backtrack(string&s,int start){
        if(start==s.length()){
            ans.push_back(temp);
            return;
        }
        for(int end=start;end<s.size();end++){
            if(isPalindrome(s,start,end)){
                temp.push_back(s.substr(start,end-start+1));
                backtrack(s,end+1);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        backtrack(s,0);
        return ans;
    }
};