bool sortBySecond(vector<int>a, vector<int>b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& v) {
        int n= v.size();
       sort(v.begin(), v.end(), sortBySecond);
       for(auto i:v)
        cout<<i[0]<<" "<<i[1]<<"\n";
       int ans =0;
       for(int i=0; i<n; ){
        int cs= v[i][0];
        int ce= v[i][1];
        int j= i+1;
        while(j<n && v[j][0] <v[i][1]){
            ans++;
            j++;
        }
        i=j;
       }
       return ans;
    }
};
