class Solution {
public:
    bool isValid(string s) {
        if(s.length()%2!=0) return false;
        stack<char>stk;
        for(char i:s){
            if(i=='[' || i=='{' || i=='('){
                stk.push(i);
            }else if(i==']' && !stk.empty() && stk.top()=='['){
                stk.pop();
            }else if(i=='}' && !stk.empty() && stk.top()=='{'){
                stk.pop();
            }else if(i==')' && !stk.empty() && stk.top()=='('){
                stk.pop();
            }else{
                return false;
            }
        }
        return stk.empty();
    }
};
