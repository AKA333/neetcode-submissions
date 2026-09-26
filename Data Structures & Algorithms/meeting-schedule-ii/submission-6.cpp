/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& v) {
        int n= v.size();

        vector<int>s, e;
        for(auto i:v){
            s.push_back(i.start);
            e.push_back(i.end);
        }
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());

        int ans=0;
        int c=0;
        int l=0, r=0;
        while(l<n){
            if(s[l]<e[r]){
                c++;
                ans = max(ans, c);
                l++;
            }
            else{
                c--;
                r++;
            }
        }
        return ans;
    }
};
