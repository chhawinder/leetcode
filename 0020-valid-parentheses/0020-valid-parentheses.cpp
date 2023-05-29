class Solution {
public:
    bool isValid(string s) {
        stack<char> k;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                k.push(s[i]);
            } else {
                if (k.empty()) {
                    return false;
                } else if ((s[i] == ')' && k.top() == '(') || 
                           (s[i] == '}' && k.top() == '{') || 
                           (s[i] == ']' && k.top() == '[')) {
                    k.pop();
                } else {
                    return false;
                }
            }
        }
        return k.empty();
    }
};