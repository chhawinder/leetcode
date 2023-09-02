class Solution {
public:
    int calculate(string s) {
        stack<int> numStack;
        stack<char> opStack;
        int num = 0;
        char sign = '+';

        for (char c : s) {
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+' || c == '-' || c == '*' || c == '/') {
                if (sign == '+') {
                    numStack.push(num);
                } else if (sign == '-') {
                    numStack.push(-num);
                } else if (sign == '*') {
                    int top = numStack.top();
                    numStack.pop();
                    numStack.push(top * num);
                } else if (sign == '/') {
                    int top = numStack.top();
                    numStack.pop();
                    numStack.push(top / num);
                }
                num = 0;
                sign = c;
            } else if (c == ' ') {
                continue;
            }
        }

        // Handle the last number and operation
        if (sign == '+') {
            numStack.push(num);
        } else if (sign == '-') {
            numStack.push(-num);
        } else if (sign == '*') {
            int top = numStack.top();
            numStack.pop();
            numStack.push(top * num);
        } else if (sign == '/') {
            int top = numStack.top();
            numStack.pop();
            numStack.push(top / num);
        }

        // Calculate the final result
        int result = 0;
        while (!numStack.empty()) {
            result += numStack.top();
            numStack.pop();
        }

        return result;
    }
};
