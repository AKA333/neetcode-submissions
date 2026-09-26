class Solution {
public:
    vector<int>dx={0, 0, 1, -1};
    vector<int>dy={1, -1, 0, 0};

    int dfs(vector<vector<int>>&v, int i, int j, vector<vector<int>>&vis){
        int n= v.size();
        int m= v[0].size();
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j] || v[i][j]==0)
            return 0;
        vis[i][j] =1;
        int t=1;
        for(int k=0; k<4; k++){
            int x= i+dx[k];
            int y= j+dy[k];
            t+= dfs(v, x, y, vis); 
        }
        return t;
    }
    int maxAreaOfIsland(vector<vector<int>>& v) {
        int n= v.size();
        int m= v[0].size();
        int ans= 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(vis[i][j]==0 && v[i][j] ==1){
                    int temp= dfs(v, i, j, vis);
                    cout<<temp<<" ";
                    ans = max(ans, temp);
                }
            }
        }
        return ans;
    }
};
