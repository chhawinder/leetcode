class Disjointset{
    vector<int>parent,size;
    public:
    Disjointset(int n){
        parent.resize(n),size.resize(n);
        for(int i=0;i<n;i++){
            parent[i]=i;
            size[i]=1;
        }
    }
    int up(int x){
         if (x == parent[x]) return x;
        return parent[x] = up(parent[x]);
    }
    bool join(int p,int q){
        int pp=up(p);
        int pq=up(q);
        if(up(pp)==up(pq))return false;
        
        if(size[pp]>size[pq]){
            parent[pq]=pp;
            size[pp]+=size[pq];
        }else{
             parent[pp]=pq;
            size[pq]+=size[pp];
        }
        return true;
    }
};


class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        Disjointset* d=new Disjointset(edges.size()+1);
        for(auto it:edges){
            if(d->join(it[0],it[1])==false)return it;
        }
        return {-1,-1};
    }
};