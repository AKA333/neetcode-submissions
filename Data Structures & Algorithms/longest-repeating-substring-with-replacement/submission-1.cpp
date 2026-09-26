class Solution {
public:
    int fn(vector<int>&vis){
        int c=0;
        int m=0;
        for(auto i:vis){
            c+=i;
            if(i>0){
                m= max(m, i);
            }
        }
        return c-m;
    }
    int characterReplacement(string s, int k) {
        int n= s.size();
        vector<int>vis(26, 0);
        int l=0, r=0;
        int ans=0;
        while(r<n){
            vis[s[r]-'A']++;
            int t= fn(vis);
            // cout<<l<<" "<<r<<"\n";
            // cout<<t<<"\n";
            while(l<n && fn(vis)>k){
                vis[s[l]-'A']--;
                l++;
            }
            ans = max(ans, r-l+1);
            r++;
        }
        return ans;
        
    }
};
