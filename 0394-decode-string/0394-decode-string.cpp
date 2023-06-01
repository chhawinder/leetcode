class Solution {
public:
    string decodeString(string s) {
    stack<string> st;
    stack<int> num;

    for (int i = 0; i < s.size(); i++) {
        if (isdigit(s[i])) {
            int val = 0;
            while (isdigit(s[i])) {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            i--; // Adjust i to point to the last digit of the number
            num.push(val);
        } else if (s[i] == ']') {
            int n = num.top();
            num.pop();
            string ck = "";
            while (st.top() != "[") {
                ck = st.top() + ck;
                st.pop();
            }
            st.pop();
            string l = "";
            while (n--) {
                l += ck;
            }
            st.push(l);
        } else {
            st.push(string(1, s[i]));
        }
    }
        string result = "";
    while (!st.empty()) {
        result = st.top() + result;
        st.pop();
    }

    return result;
}

};