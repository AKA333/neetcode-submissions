class Solution {
public:
    void fn(vector<int>& v, int k, vector<vector<int>>& ans, 
        vector<int> &t, int s, int i){
        if(i>=v.size() || s>k)
            return ;
        if(s==k){
            ans.push_back(t);
            return;
        }
        t.push_back(v[i]);
        fn(v, k, ans, t, s+v[i], i);
        t.pop_back();
        fn(v, k, ans, t, s, i+1);

    }
    vector<vector<int>> combinationSum(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int>t;
        int s=0;
        fn(v, k, ans, t, s, 0);
        return ans;
    }
};
