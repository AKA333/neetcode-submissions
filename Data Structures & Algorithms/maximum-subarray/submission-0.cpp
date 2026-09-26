class Solution {
public:
    int maxSubArray(vector<int>& v) {
        int cs= 0;
        int ans= INT_MIN;
        for(auto i:v){
            cs+= i;
            ans= max(ans, cs);
            if(cs<0)
                cs=0;
        }
        return ans;
        
    }
};
