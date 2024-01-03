class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int sec_dev=0,sol=0;
        for(int i=0;i<bank.size();i++){
            int sdr=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')sdr++;
            }
            sol+=sdr*sec_dev;
            if(sdr!=0)sec_dev=sdr;
        }
        return sol;
        
    }
};