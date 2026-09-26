class Solution {
public:
    vector<int>dx= {0, 0, 1, -1};
    vector<int>dy= {1, -1, 0, 0};
    void islandsAndTreasure(vector<vector<int>>& v) {
        int n= v.size();
        int m= v[0].size();
        queue<pair<int, int>> q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] ==0)
                    q.push({i, j});
            }
        }
        int c=0;
        vector<vector<int>> ans= v;
        while(!q.empty()){
            int l= q.size();
            while(l--){
                auto t= q.front();
                q.pop();
                int x= t.first;
                int y= t.second;
                if(v[x][y]==-1) 
                    continue;
                v[x][y] = min(v[x][y], c);
                for(int j=0; j<4; j++){
                    int tx= x+ dx[j];
                    int ty= y+ dy[j];
                    if(tx<0||tx>=n||ty<0||ty>=m|| v[tx][ty]!= 2147483647)
                        continue;
                    q.push({tx, ty});
                }
            }
            c++;
        }
    }
};
