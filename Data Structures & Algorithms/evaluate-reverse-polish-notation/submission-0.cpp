class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (const string& i : tokens) {
            if (i == "+" || i == "-" || i == "*" || i == "/"  ) {
                int temp1 = stk.top();
                stk.pop();
                int temp2 = stk.top();
                stk.pop();
                switch(i[0]){
                    case '+':
                        stk.push(temp2 + temp1);
                        break;
                    case '-':
                        stk.push(temp2 - temp1);
                        break;
                    case '*':
                        stk.push(temp2 * temp1);
                        break;
                    case '/':
                        stk.push(temp2 / temp1);
                        break;
                }
            } else {
                stk.push(stoi(i));
            }
        }
        return stk.top();
    }
};