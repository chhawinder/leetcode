class Solution {
public:
    long long maximumHappinessSum(vector<int>& h, int k) {
        priority_queue<int>pq;
        for(int i=0;i<h.size();i++)pq.push(h[i]);
        long long int count=0;
        long long int res=0;
        while(pq.size()&&k){
            if(pq.top()-count>0){
                res+=pq.top()-count;
                pq.pop();
            }
            else{
                break;
            }
            count++;k--;
        }
        return res;
        
    }
};