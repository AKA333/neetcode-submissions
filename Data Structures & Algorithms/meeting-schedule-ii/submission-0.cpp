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
        vector<int>s= {};
        vector<int>e= {};
        for(auto i:v){
            s.push_back(i.start);
            e.push_back(i.end);
        }
        int ans= 0;
        sort(s.begin(), s.end());
        sort(e.begin(), e.end());
        int n= v.size();
        int i=0, j=0;
        int c=0;
        while(i<n && j<n){
            if(s[i]<e[j]){
                c++;
                i++;
            }
            else{
                c--;
                j++;
            }
            ans = max(ans, c);
        }
        return ans;
    }
};
