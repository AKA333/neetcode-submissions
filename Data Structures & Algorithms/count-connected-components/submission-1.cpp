class Solution {
public:
    void dfs(int n, int i, vector<vector<int>>&adj, vector<int>&vis){
        if(i>=n || vis[i])
            return;
        vis[i]=1;
        for(auto it: adj[i]){
            if(!vis[it])
                dfs(n, it, adj, vis);
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        int ans=0;
        vector<int>vis(n, 0);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(n, i, adj, vis);
                ans++;
            }
        }
        return ans;
    }
};
