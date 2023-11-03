class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        vector<int>vis(arr.size(),0);
	for(int i=0;i<arr.size();i++){
		vis[arr[i]]++;
		if(vis[arr[i]]>1)return arr[i];
	}
	return -1;
    }
};