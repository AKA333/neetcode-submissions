class Solution {
public:
    bool fn(vector<vector<int>> &v, int i, vector<int> &vis, int p){
        int n= v.size();
        if(i>=n || vis[i]==1)
            return 1;
        vis[i] = 1;
        for(int j=0; j<v[i].size(); j++){
            if(vis[v[i][j]]==1 && v[i][j] != p)
                return 0;
            if(!fn(v, v[i][j], vis, i))
                return 0;
        }
        return 1;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>v(n);
        for(auto i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int>vis(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                ans++;
                if(!fn(v, i, vis, -1))
                    return false;
            }
        }
        if(ans>1)
            return 0;
        return 1;
    }
};
