class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;

        for (const string& token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int operand2 = s.top(); s.pop();
                int operand1 = s.top(); s.pop();
                if (token == "+") s.push(operand1 + operand2);
                else if (token == "-") s.push(operand1 - operand2);
                else if (token == "*") s.push(operand1 * operand2);
                else if (token == "/") s.push(operand1 / operand2);
            } else {
                s.push(stoi(token));
            }
        }

        return s.top();

    }
};
