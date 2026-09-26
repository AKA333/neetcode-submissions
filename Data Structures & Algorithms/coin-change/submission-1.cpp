class Solution {
public:
    int fn(vector<int>& v, int k, vector<int>&dp, int i){
        if(k==0 )
            return 0;
        if(k<0 || i<0)
            return INT_MAX;
        if(dp[k]!= -1)
            return dp[k];
        int nt= fn(v, k, dp, i-1);
        int t= fn(v, k-v[i], dp, v.size()-1);
        t = t==INT_MAX? t:1+t;
        dp[k] = min(t,nt);
        return dp[k];
    }
    int coinChange(vector<int>& v, int k) {
        vector<int>dp(k+1, -1);
        if(k==0)
            return 0;
        dp[0]=0;
        fn(v, k, dp, v.size()-1);
        return dp[k]!=INT_MAX? dp[k]:-1;
    }
};
