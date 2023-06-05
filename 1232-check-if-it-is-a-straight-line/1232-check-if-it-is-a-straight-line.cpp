class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        if(coordinates.size()<=2)return true;
        
        int x1=coordinates[0][0],y1=coordinates[0][1],x2=coordinates[1][0],y2=coordinates[1][1];
        if(x1==x2){
            for(auto it:coordinates){
                if(it[0]!=x1)return false;
            }
            return true;
        }
           float m = (float)(y2 - y1) / (x2 - x1);
        float c = y1 - m * x1;
        
        for(int i=2;i<coordinates.size();i++){
            if(coordinates[i][1]!=m*coordinates[i][0]+c)return false;
        }return true;
        
       
    }
};