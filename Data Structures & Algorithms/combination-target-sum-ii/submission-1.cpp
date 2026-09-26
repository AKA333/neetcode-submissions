class Solution {
public:
    void fn(vector<int>& v, int k, vector<int>&t, 
        vector<vector<int>>&ans, int i, int s){
            if(s==k){
                ans.push_back(t);
                return ;
            }
            int j=i+1; 
            while(j<v.size() && v[j] ==v[i]){
                j++;
            }
            if(i>=v.size() || s>k)
                return ;
            t.push_back(v[i]);
            fn(v, k, t, ans, i+1, s+v[i]);
            t.pop_back();
            
            
            fn(v, k, t, ans, j, s);
    }
    vector<vector<int>> combinationSum2(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<int>t;
        vector<vector<int>>ans;
        int s=0;
        fn(v, k, t, ans, 0, s);
        return ans;
    }
};
