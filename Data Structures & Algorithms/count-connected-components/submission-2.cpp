class Solution {
public:
    void dfs(vector<vector<int>>& v, int i, vector<int>& vis){
        if(i>=v.size() || vis[i]!=0)
            return ;
        vis[i] = 1;
        for(int j=0; j<v[i].size(); j++){
            if(vis[v[i][j]])
                continue;
            dfs(v, v[i][j], vis);
        }
        vis[i] = 2;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> v(n);
        for(auto i:edges){
            v[i[0]].push_back(i[1]);
            v[i[1]].push_back(i[0]);
        }
        vector<int>vis(n, 0);
        int ans=0;
        for(int i=0; i<n; i++){
            if(vis[i])
                continue;
            ans++;
            // cout<<"i:"<<" "<<i<<"\n";
            dfs(v, i, vis);
        }
        // for(auto i:vis)
        //     cout<<i<<" ";
        return ans;
    }
};
