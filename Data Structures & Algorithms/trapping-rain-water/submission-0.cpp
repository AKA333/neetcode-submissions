class Solution {
public:
    int trap(vector<int>& v) {
        int n = v.size();
        int lm= v[0];
        int rm= v[n-1];
        int ans=0;
        int l=0, r=n-1;
        while(l<r){
            if(lm<rm){
                l++;
                lm= max(lm, v[l]);
                ans+=abs(lm-v[l]); 
            }
            else{
                r--;
                rm = max(rm, v[r]);
                ans+= abs(rm-v[r]);
            }
        }
        return ans;
    }
};
