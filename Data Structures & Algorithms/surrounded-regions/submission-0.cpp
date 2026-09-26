class Solution {
public:
    vector<int> dx= {0, 0, 1, -1};
    vector<int> dy= {1, -1, 0, 0};
    void solve(vector<vector<char>>& v) {
        int n = v.size();
        int m= v[0].size();
        vector<vector<int>>vis(n, vector<int>(m, 0));

        queue<pair<int,int>>q;
        for(int i=0; i<n; i++){
            if(v[i][0]=='O'){
                q.push({i, 0});
            }
            if(v[i][m-1]=='O')
                q.push({i, m-1});
        }
        for(int j=0; j<m; j++){
            if(v[0][j]=='O')
                q.push({0, j});
            if(v[n-1][j]=='O')
                q.push({n-1, j});
        }
        while(!q.empty()){
            auto t= q.front();
            q.pop();
            int x= t.first;
            int y= t.second;
            v[x][y] = 'Y';
            vis[x][y] = 1;
            for(int k=0; k<4; k++){
                int nx= x+dx[k];
                int ny= y+dy[k];
                if(nx<0 || nx>=n || ny <0 || ny>=m || vis[nx][ny] ||  v[nx][ny]!= 'O')
                    continue;
                q.push({nx, ny});
            }
        }
        // for(auto i:v){
        //     for(auto j:i){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] != 'Y')
                    v[i][j] = 'X';
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] == 'Y')
                    v[i][j] = 'O';
            }
        }
    }
};
