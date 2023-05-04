class Solution {
public:
    string predictPartyVictory(string senate) {
        while(true){
            for(int i=0;i<senate.length();i++){
                bool b=0;
                for(int j=i+1;j<senate.length();j++){
                    if(senate[i]=='R'&&senate[j]=='D'||senate[i]=='D'&&senate[j]=='R'){
                        senate.erase(senate.begin()+j);
                        b=1;
                        break;
                        
                    }
                }
                if(b==0){
                    for(int j=0;j<i;j++){                              if(senate[i]=='R'&&senate[j]=='D'||senate[i]=='D'&&senate[j]=='R'){
                        senate.erase(senate.begin()+j);
                        b=1;
                        break;
                        
                    }
                    }
                }
                if(b==0){
                    if(senate[i]=='R')return "Radiant";
                    else return "Dire";
                }
            }
        }
    }
};