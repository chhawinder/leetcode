class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int i=0;
        int sol=0;
        while(i<neededTime.size()-1){
            int sum=neededTime[i];int m=neededTime[i];
            while(colors[i]==colors[i+1]){
                sum+=neededTime[i+1];
                m=max(m,neededTime[i+1]);
                i++;
            }
            sol+=sum-m;
            i++;
        }
        return sol;
    }
    
};