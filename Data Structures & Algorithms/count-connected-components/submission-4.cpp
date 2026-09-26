class Solution {
public:
    vector<int>par;
    vector<int>rank;

    int find(int u){
        if(u==par[u])
            return u;
        return par[u] = find(par[u]);
    }

    void unionnn (int u, int v){
        int pu= find(u);
        int pv= find(v);
        if(pu==pv)
            return ;
        if(rank[pu]>=rank[pv]){
            par[pv]= pu;
            rank[pu]+= rank[pv];
        }
        else{
            par[pu]= pv;
            rank[pv]+= rank[pu];
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        par.resize(n);
        rank.resize(n, 1);
        for(int i=0; i<n; i++){
            par[i]= i;
        }
        for(auto i: edges){
            int u= i[0];
            int v= i[1];
            unionnn(u, v);
        }
        unordered_set<int>s;
        for(auto i:par)
            s.insert(find(i));
        for(auto i:par)
            cout<<i<<" ";
        
        return s.size();
    }

   
};
