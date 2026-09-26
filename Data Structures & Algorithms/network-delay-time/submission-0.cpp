class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> v(n); // assign size to vector v
        for(auto i:times){
            v[i[0]-1].push_back({(i[1]-1), i[2]});
        }
        vector<int>vis(n, 0);
        vector<int>cost(n, INT_MAX);
        cost[k-1]=0;
        priority_queue<pair<int, int>, 
            vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k-1});
        int ans= 0;
        while(!pq.empty()){
            pair<int, int>t= pq.top();
            pq.pop();

            int u= t.second;
            int c= t.first;
            cost[u]= min(cost[u], c);
            ans= max(ans,cost[u]);
            vis[u]=1;
            for(auto j:v[u]){
                if(vis[j.first])   
                    continue;
                // cout<<j.first<<" "<<j.second<<" cost:"<<c+cost[u]<<"\n";
                pq.push({cost[u]+j.second, j.first});
            }
        }
        for(auto i:cost){
            if(i==INT_MAX)
                return -1;
        }
        return ans;
    }
};
