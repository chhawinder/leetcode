class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int,int>m;
        for(int i=0;i<tasks.size();i++){
            m[tasks[i]]++;
        }
        int count =0;
        for(auto k:m){
            if(k.second==1)return -1;
            count+=k.second/3;
            k.second=k.second%3;
            count+=k.second/2;
            k.second%=2;
            if(k.second){
                count+=k.second;
                k.second=0;
            }
        
        }
        return count;
    }
};