class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int i=0;
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        while(i<intervals.size()){
            int l=intervals[i][0];
            int h=intervals[i][1];
            int k=i;
            while(k<intervals.size()-1&&h>=intervals[k+1][0]){
                h=max(h,intervals[k+1][1]);
                k++;
                cout<<k<<" "<<i<<" ";
            }cout<<endl;
            if(k==i)i++;
            else i=k+1;
            res.push_back({l,h});
            
        }
        return res;
    }
};