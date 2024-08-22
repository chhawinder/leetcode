class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        int i = 0;
        while(num != 0){
            if(!(num & 1)) ans += pow(2, i);
            i++;
            num = num >> 1;
        }
        return ans;
        
    }
};