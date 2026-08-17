class Solution {
public:
    bool isPalindrome(string s) {
s.erase(remove_if(s.begin(), s.end(),
                      [](unsigned char c) {
                          return !isalnum(c);
                      }),
            s.end());

transform(s.begin(), s.end(), s.begin(),
          [](unsigned char c) {
              return tolower(c);
          });
        bool isPal = true;
        for(int i=0;i<(s.size()/2);i++){
            if(s[i]!=s[s.size()-1-i]){
                // cout<<s[i]<<endl;
                return false;
            }
        }
        return true;
    }
};
