class Solution {
public:
    void dfs(vector<vector<char>>& v, vector<vector<int>>& vis, int x, int y){
        int n = v.size();
        int m = v[0].size();
        if (x<0 || x>=n || y<0 || y>=m || vis[x][y] ==1 || v[x][y] =='0'){
            return ;
        }
        vis[x][y] = 1;
        dfs(v, vis, x+1, y);
        dfs(v, vis, x-1, y);
        dfs(v, vis, x, y+1);
        dfs(v, vis, x, y-1);
    }
    int numIslands(vector<vector<char>>& v) {
        int n = v.size();
        int m = v[0].size();
        int ans =0;
        vector<vector<int>>vis(n, vector<int>(m, 0));
        for(int i=0; i<n;i++){
            for(int j=0; j<m; j++){
                if (vis[i][j] ==0 && v[i][j] =='1'){
                    dfs(v, vis, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};
