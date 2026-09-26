class Solution {
public:
    vector<int>dx= {0, 0, 1, -1};
    vector<int>dy= {1, -1, 0, 0};
    int orangesRotting(vector<vector<int>>& v) {
        queue<pair<int, int>>q;
        int n= v.size();
        int m= v[0].size();

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(v[i][j]==2)
                    q.push({i, j});
            }
        }
        int ans=0;
        while(!q.empty()){
            int l= q.size();
            while(l--){
                auto t= q.front();
                q.pop();
                int i= t.first;
                int j= t.second;
                v[i][j] = 2;
                for(int k=0; k<4; k++){
                    int x= i+dx[k];
                    int y= j+dy[k];
                    if(x<0 || x>=n || y<0 || y>=m || v[x][y] !=1)
                        continue;
                    q.push({x, y});
                }

            }
            ans++;
        }
        for(auto i:v){
            for(auto j:i){
                if (j==1)
                    return -1;
            }
        }
        return ans==0? 0: ans-1;
    }
};
