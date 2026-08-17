class Solution {
public:
    bool isValid(string s) {
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
        if(stk.empty()){
            return true;
        }else{
            return false;
        }
    }
};
