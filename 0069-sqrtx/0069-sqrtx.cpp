class Solution {
public:
    int mySqrt(int x) {
        long long l = 1, h = x;
        long long ans = 0;
        while (l <= h) {
            long long mid = (l + h) / 2;
            if (mid * mid == x)
                return mid;
            if (mid * mid < x) {
                ans = max(ans, mid);
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return ans;
        
    }
};