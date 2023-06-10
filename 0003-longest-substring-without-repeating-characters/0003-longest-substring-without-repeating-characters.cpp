#include<bits/stdc++.h>
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         int i = 0, j = 0, ans = 0;
        set<char> check;
        while (j < s.size()) {
            if (check.find(s[j]) == check.end()) {
                check.insert(s[j]);
                ans = max(ans, (int)check.size());
                ++j;
            } else {
                check.erase(s[i]);
                ++i;
            }
        }
        return ans;
    }
};