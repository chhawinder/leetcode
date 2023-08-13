class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> g;
        for (int i = 0; i < equations.size(); i++) {
            g[equations[i][0]].push_back({equations[i][1], values[i]});
            g[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        
        vector<double> res(queries.size(), -1.0);
        for (int j = 0; j < queries.size(); j++) {
            string start = queries[j][0];
            string end = queries[j][1];
            
            if (g.find(start) == g.end() || g.find(end) == g.end()) {
                continue;
            }
            
            queue<pair<string, double>> q;
            q.push({start, 1.0});
            
            unordered_set<string> visited;
            visited.insert(start);
            
            bool flag = false;
            while (!q.empty()) {
                auto current = q.front();
                q.pop();
                
                if (current.first == end) {
                    flag = true;
                    res[j] = current.second;
                    break;
                }
                
                for (const auto& neighbor : g[current.first]) {
                    if (visited.find(neighbor.first) == visited.end()) {
                        visited.insert(neighbor.first);
                        q.push({neighbor.first, current.second * neighbor.second});
                    }
                }
            }
            
            if (!flag) {
                res[j] = -1.0;
            }
        }
        
        return res;
    }
};
