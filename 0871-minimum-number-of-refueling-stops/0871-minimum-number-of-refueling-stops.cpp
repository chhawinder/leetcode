class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // int tf=0;
        // for(int i=0;i<stations.size();i++){
        //     tf+=stations[i][1];
        //     // pq.push({stations[i][0],stations[i][1]});
        // }
        // if(tf<target)return -1;
        if(stations.size()==0){
            if(target<=startFuel)return 0;
            return -1;
        }
        priority_queue<int>fuel;
        int dis=startFuel;
        int sol=0;int i=0;
        while(i<stations.size()){
            while(i<stations.size()&&dis>=stations[i][0]){
                if(dis>=target)return sol;
                fuel.push(stations[i][1]);i++;
            }
            if(dis>=target)return sol;
            if(fuel.size()==0&&stations.size()!=i)return -1;
            
            dis+=fuel.top();fuel.pop();
            sol++;
            
            
        }
        while(dis<target){
            if(fuel.size()){
                dis+=fuel.top();fuel.pop();sol++;
            }else{
                return -1;
            }
        }
        return sol;
        
    }
};