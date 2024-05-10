class Solution {
public:
    static bool cmp(const pair<vector<int>,double>&a ,const pair<vector<int>,double>&b)
    {
        return a.second< b.second;
    }
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n  = arr.size();
        vector<pair<vector<int>,double>>ans;
        for(int i = 0 ;i < n-1 ;i++)
        {
            for(int j = i+1 ; j< n ;j++)
            {
                vector<int>temp;
                temp.push_back(arr[i]);
                temp.push_back(arr[j]);
                ans.push_back({temp,arr[i]/(arr[j]*1.0)});
            }
        }

        sort(ans.begin(),ans.end(),cmp);
        return ans[k-1].first;

    }
};