class Solution {
public:
    vector<int>par;
    vector<int>sz;
    int find(int u){
        if(u==par[u])
            return u;
        return par[u]= find(par[u]);
    }

    void unionn(int u, int v){
        u= find(u);
        v= find(v);

        if(u==v)
            return;
        if(sz[u]>=sz[v]){
            par[v]= u;
            sz[u] += sz[v];
        }
        else{
            par[u]= v;
            sz[v]+= sz[u];
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n= edges.size();
        par.resize(n);
        for(int i=0; i<n; i++){
            par[i]= i;
        }
        sz.resize(n, 1);
        for(auto i:edges){
            int u= i[0];
            int v= i[1];
            if(find(u-1)==find(v-1)){
                return i;
            }
            unionn(u-1, v-1);
        }
        return {};
    }
};
