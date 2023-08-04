class Solution {
public:
    int minEatingSpeed(vector<int>& v, int ho) {
         int k = 0;
        for (int i = 0; i < v.size(); i++)
            k = max(k, v[i]);

        int l = 1, h = k;
        int ans = 1e9 + 7;

        while (l <= h) {
            int mid = (l + h) / 2;
            long long int hours = 0;

            for (int i = 0; i < v.size(); i++)
                hours += ceil(static_cast<double>(v[i]) / mid);

            if (hours <= ho) {  // Use `<=` instead of `<`
                ans = min(ans, mid);
                h = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        if (ans == 1e9 + 7)
            return -1;
        return ans;
        
    }
};