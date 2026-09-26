#define inf 2147483647
class Solution {
public:
    vector<int>dx={0,0, 1, -1};
    vector<int>dy= {1, -1, 0, 0};
    void islandsAndTreasure(vector<vector<int>>& v) {
        int n= v.size();
        int m= v[0].size();
        queue<pair<int, int>>q;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j] ==0){
                    q.push({i, j});
                }
            }
        }
        int c=0;
        while(!q.empty()){
            int l= q.size();
            while(l--){
                auto cur= q.front();
                q.pop();
                int x= cur.first;
                int y= cur.second;
                v[x][y] = min(v[x][y], c);
                for(int k=0; k<4; k++){
                    int nx= x+dx[k];
                    int ny= y+dy[k];
                    if(nx<0 || nx>=n || ny<0 || ny>=m || (v[nx][ny]!=inf))
                        continue;
                    q.push({nx, ny});
                }
            }
            c++;
        }
    }
};
