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

bool sortByFirst(Interval a, Interval b){
    return a.start<b.start;
}

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& v) {
        sort(v.begin(), v.end(), sortByFirst);
        int n= v.size();
        for(int i=0; i<n; ){
            int j= i+1;
            while(j<n && v[j].start<v[i].end){
                return 0;
            }
            i=j;
        }
        return 1;
    }
};
