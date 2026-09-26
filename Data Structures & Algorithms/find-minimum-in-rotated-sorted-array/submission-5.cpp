class Solution {
public:
    int findMin(vector<int> &v) {
        int n= v.size();
        int l=0, r=n-1;
        if(v[l]<=v[r])
            return v[l];
        int ans = INT_MAX;
        while(l<=r){
            int m= l+(r-l)/2;
            ans = min(ans, v[m]);
            if(v[l]<=v[m]){
                ans= min(ans, v[l]);
                l=m+1;
            }
            else{
                r=m-1;
            }
        }
        return ans;
    }
};
