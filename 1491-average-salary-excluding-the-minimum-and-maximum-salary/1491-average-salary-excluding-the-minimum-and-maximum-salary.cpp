class Solution {
public:
    double average(vector<int>& salary) {
        int m=INT_MAX,mx=INT_MIN;
        double res=0.00000;
        for(int i=0;i<salary.size();i++){
            res+=salary[i];
            m=min(m,salary[i]);
            mx=max(mx,salary[i]);
        }
        res=res-m-mx;
        res=res/(salary.size()-2);
        return res;
        
    }
};