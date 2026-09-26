class Solution {
public:
    int search(vector<int>& v, int k) {
        int n= v.size();
        int l=0; int r=n-1;
        while(l<=r){
            int m= l+(r-l)/2;
            if(v[m]==k)
                return m;
            if(v[l]<=v[m]){
                if(v[l]<=k && k<=v[m]){
                    r= m-1;
                }
                else{
                    l= m+1;
                }
            }
            else{
                if(k<=v[r] && k>=v[m]){
                    l=m+1;
                }
                else
                    r= m-1;
            }
        }
        return -1;
    }
};
