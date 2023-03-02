//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int res=1;
        queue<int>q;
        q.push(1);
        vector<int>v(V+1,0);
        v[0]=1;
        while(q.size()!=0){
            int temp=q.front();
            q.pop();
            if(v[temp]==0){
                v[temp]=1;
                for(int i=0;i<V;i++){
                    if(adj[temp-1][i]==1&&v[i+1]==0)
                     q.push(i+1);
                }
            }
            if(q.size()==0){
                for(int i=1;i<V+1;i++){
                    if(v[i]==0){
                        q.push(i);
                        res++;
                        break;
                    }
                }
            }
        }
        return res;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends