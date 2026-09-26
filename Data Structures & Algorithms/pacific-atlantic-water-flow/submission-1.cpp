class Solution {
public:
    vector<int>dx= {1, -1, 0, 0};
    vector<int>dy= {0, 0, 1, -1};
    void dfs(vector<vector<int>>& v, vector<vector<int>>& vis, int i, int j){
        int n=v.size();
        int m= v[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] ==1)
            return ;
        vis[i][j]=1;
        for(int k=0; k<4; k++){
            int x= i+dx[k];
            int y= j+dy[k];
            if(x<0 || x>=n || y<0 || y>=m || vis[x][y] || v[x][y] <v[i][j])
                continue ;
            dfs(v, vis, x, y);
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& v) {
        int n= v.size();
        int m= v[0].size();
        vector<vector<int>> pac(n, vector<int>(m, 0));
        vector<vector<int>> atl(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            if(pac[i][0]==0){
                dfs(v, pac, i, 0);
            }
        }
        for(int j=0; j<m; j++){
            if(pac[0][j]==0){
                dfs(v, pac, 0, j);
            }
        }

        for(int i=0; i<n; i++){
            if(atl[i][m-1]==0)
                dfs(v, atl, i, m-1);
        }
        for(int j=0; j<m; j++){
            if(atl[n-1][j]==0)
                dfs(v, atl, n-1, j);
        }
        // for(auto i:pac){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        // cout<<"*******\n";
        // for(auto i:atl){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<vector<int>> ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] ==1 && atl[i][j] ==1)
                    ans.push_back({i, j});
            }
        }
        return ans;

        
    }
};
