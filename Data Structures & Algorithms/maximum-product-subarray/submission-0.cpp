class Solution {
public:
    int maxProduct(vector<int>& v) {
        int n= v.size();
        int ans= INT_MIN;
        int cp=1;
        for(auto i:v){
            cp *= i;
            ans = max(ans, cp);
            if(cp==0){
                cp=1;
            }
        }
        cp=1;
        for(int i=n-1; i>=0; i--){
            cp*= v[i];
            ans= max(ans, cp);
            if(cp==0)
                cp=1;
        }
        return ans;
    }
};
