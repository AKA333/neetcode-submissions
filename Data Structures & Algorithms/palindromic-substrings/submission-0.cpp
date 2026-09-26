class Solution {
public:
    int fn(string s, int i, int j){
        int n= s.size();
        int c=0;
        while(i>= 0 && j<n && s[i]==s[j]){
            i--; j++;
            c++;
        }
        return c;
    }
    int countSubstrings(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0; i<n; i++){
            ans+= fn(s, i, i);
        }
        for(int i=0; i<n-1; i++){
            ans+= fn(s, i, i+1);
        }
        return ans;
    }
};
