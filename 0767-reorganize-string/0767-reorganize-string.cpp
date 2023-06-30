class Solution {
public:
    string reorganizeString(string s) {
        map<char,int>m;
        for(int i=0;i<s.size();i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        string res="";
        while(pq.size()){
            int freq=pq.top().first;
            char ch=pq.top().second;
            pq.pop();
            res+=ch;
            if(pq.size()){
                int f=pq.top().first;
            char c=pq.top().second;
                pq.pop();
                res+=c;
                if(f-1>0){
                    pq.push({f-1,c});
                }
            }
            if(freq-1>0){
                    pq.push({freq-1,ch});
                }
        }
        for(int i=0;i<res.size()-1;i++){
            if(res[i]==res[i+1])return "";
        }
        return res;
        
    }
};