class Solution {
public:
    double help(vector<int>& quality, vector<int>& wage, int k,int i){
        double ratio=double(wage[i])/quality[i];
        priority_queue<double,vector<double>,greater<double>>pq;
        for(int j=0;j<wage.size();j++){
            if(quality[j]*ratio>=wage[j]){
                pq.push(quality[j]*ratio);
            }
        }
        double sol=0;
        while(k--){
            if(pq.size()==0)return INT_MAX;
            sol+=pq.top();pq.pop();
        }
        return sol;
    }
    
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
         vector<vector<double>> workers;
        for (int i = 0; i < q.size(); ++i)
            workers.push_back({(double)(w[i]) / q[i], (double)q[i]});
        sort(workers.begin(), workers.end());
        double res = DBL_MAX, qsum = 0;
        priority_queue<int> pq;
        for (auto worker: workers) {
            qsum += worker[1], pq.push(worker[1]);
            if (pq.size() > K) qsum -= pq.top(), pq.pop();
            if (pq.size() == K) res = min(res, qsum * worker[0]);
        }
        return res;
        
    }
};