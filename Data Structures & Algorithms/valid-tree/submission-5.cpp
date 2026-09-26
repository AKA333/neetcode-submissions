class Solution {
public:
    vector<int>par;
    vector<int>sz;
    int find(int u){
        if(u==par[u])
            return u;
        return par[u] = find(par[u]);
    }
    void unionNode(int u, int v){
        u= find(u);
        v= find(v);

        if(u==v)
            return;
        if(sz[u]>=sz[v]){
            par[v]=u;
            sz[u]+= sz[v];
        }
        else{
            par[v]= u;
            sz[v]+= sz[u];
        }
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        sz.assign(n, 1);
        par.resize(n);
        for(int i=0; i<n; i++)
            par[i]= i;
        for(auto edge: edges){
            int u= edge[0];
            int v= edge[1];

            if(find(u)==find(v))
                return 0;

            unionNode(u, v);
        }
        int cp=-1;
        for(int i=0; i<n; i++){
            int p= find(i);
            // cout<<p<<" ";
            if(cp ==-1){
                cp= p; continue;
            }
            if(p!=cp)
                return 0;
        }
        return 1;
    }
};
