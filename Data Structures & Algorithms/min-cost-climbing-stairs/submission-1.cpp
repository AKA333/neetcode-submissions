class Solution {
public:
    int minCostClimbingStairs(vector<int>& v) {
        int n= v.size();
        vector<int>dp(n+1, 0);
        dp[0]= 0;
        dp[1]= 0;
        for(int i=2; i<=n; i++){
            dp[i]= min(v[i-1]+dp[i-1], v[i-2]+dp[i-2]);
        }
        return dp[n];
    }
};
