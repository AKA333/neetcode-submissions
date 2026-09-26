class Solution {
public:
    void fn(vector<int>& v, vector<vector<int>>& ans, vector<int>&t, int i){
        if(i>=v.size())
            return ;
        t.push_back(v[i]);
        ans.push_back(t);
        fn(v, ans, t, i+1);
        t.pop_back();
        fn(v, ans, t, i+1);
    }
    vector<vector<int>> subsets(vector<int>& v) {
        vector<int>t;
        vector<vector<int>> ans;
        ans.push_back(t);
        fn(v, ans, t, 0);


        return ans;
    }
};
