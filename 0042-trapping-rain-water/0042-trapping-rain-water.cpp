class Solution {
public:
    int trap(vector<int>& arr) {
        int n=arr.size();
    vector<int>pre;
   int p=-1;
    for(int i=0;i<n;i++){
        p=max(arr[i],p);
        pre.push_back(p);
    }
    vector<int>suf;
    int s=-1;
    for(int i=n-1;i>=0;i--){
         s=max(arr[i],s);
        suf.push_back(s);
    }
    reverse(suf.begin(),suf.end());
    int sol=0;
    for(int i=0;i<n;i++){
       sol+= min(pre[i],suf[i])-arr[i];
    }
    return sol;
        
    }
};