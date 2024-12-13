class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<int>marked(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++){
            pq.push({nums[i],i});
        }
        long long int ans=0;
        while(pq.size()){
            int temp=pq.top().first;int id=pq.top().second;pq.pop();
            if(marked[id]==0){
                ans+=temp;
                cout<<temp<<" ";
                marked[id]=1;
                if(id!=0)marked[id-1]=1;
                if(id!=n-1)marked[id+1]=1;
            }
            
        }cout<<endl;
        return ans;
        
        
    }
};