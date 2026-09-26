class Solution {
public:
    int fn(vector<int>&v, int l, int r){
        int p1= v[l];
        int p2= 0;
        int ans=max(p1, p2);
        for(int i=l+1; i<=r; i++){
            int t= p1;
            int nt= v[i]+ p2;
            int cur = max(t, nt);
            p2= p1;
            p1= cur;
        }
        return p1;
    }
    int rob(vector<int>& v) {
        int n= v.size();
        if(n==1)
            return v[0];
        // vector<int>dp(n, 0);
        // dp[0]= v[0];
        // dp[1]= max(v[0], v[1]);
        // for(int i=2; i<n; i++){
        //     if(i==n-1){
                
        //     }
        //     dp[i]= max(dp[i-1], dp[i-2]+v[i]);
        // }
        // return dp[n-1];

        int x= fn(v, 0, n-2);
        int y= fn(v, 1, n-1);
        return max(x, y);
    }
};
