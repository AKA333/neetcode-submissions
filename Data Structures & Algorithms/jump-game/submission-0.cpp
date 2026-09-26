class Solution {
public:
    bool canJump(vector<int>& v) {
        int n= v.size();
        if(v.empty())
            return 0;
        int m=0;
        for(int i=0; i<n; i++){
            if(i<=m){
                m= max(m, i+v[i]);
            }
        }
        if(m>=n-1)
            return 1;
        return 0;
    }
};
