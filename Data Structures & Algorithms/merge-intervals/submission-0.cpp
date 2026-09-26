class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n= v.size();
        vector<vector<int>> ans;
        for(int i=0; i<n; ){
            int cs= v[i][0];
            int ce= v[i][1];
            int j=i+1; 
            while(j<n && v[j][0]<=ce){
                cs = min(cs, v[j][0]);
                ce = max(ce, v[j][1]);
                j++;
            }
            ans.push_back({cs, ce});
            i=j;
        }
        return ans;
    }
};
