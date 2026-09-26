class Solution {
public:
    int jump(vector<int>& v) {
        int n= v.size();
        int ans=0;
        int cs=0;
        int m=0;
        for(int i=0; i<n; i++){
            cs= max(cs, i+v[i]);
            if(m>=n-1)
                return ans;
            if(i>=m){
                ans++;
                m= max(m, cs);
            }
        }
        return ans;
    }
};
