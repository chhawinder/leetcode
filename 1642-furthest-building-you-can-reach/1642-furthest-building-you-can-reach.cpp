class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        vector<int>req_bricks(heights.size(),0);
        for(int i=0;i<heights.size()-1;i++){
            if(heights[i]<heights[i+1]){
                req_bricks[i]=heights[i+1]-heights[i];
              //  cout<<req_bricks[i]<<" ";
            }
        }
        priority_queue<int,vector<int>, greater<int>>pq;
        int i;
        for( i=0;i<req_bricks.size();i++){
            if(req_bricks[i]!=0&&pq.size()<ladders){
                //cout<<req_bricks[i]<<" ";
                pq.push(req_bricks[i]);
            }else if(req_bricks[i]!=0){
                
                int k=req_bricks[i];
                if(pq.size())
                    k=min(req_bricks[i],pq.top());
                
                if(k<=bricks){
                    bricks=bricks-k;
                    if(pq.size()&&req_bricks[i]>pq.top()){
                         //cout<<req_bricks[i]<<" ";
                        pq.pop();
                    pq.push(req_bricks[i]);
                    }
                    
                }else{
                    break;
                }
            }
        }
        if(i==req_bricks.size())return i-1;
        return i;
    }
};
