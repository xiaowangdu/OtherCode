/**
 * Definition of Interval:
 * classs Interval {
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    /**
     * @param intervals: an array of meeting time intervals
     * @return: the minimum number of conference rooms required
     */
    
    //还可以使用优先队列进行优化
    //priority_queue
    
    static bool cmp(const Interval &a, const Interval &b){
        return a.start < b.start;
    }
     
    int minMeetingRooms(vector<Interval> &intervals) {
        // Write your code here
        if(intervals.size() <= 0){
            return 0;
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
    
        vector<int> res;
        res.push_back(intervals[0].end);
        for(int i = 1; i < intervals.size(); i++){
            
            int fastfinished = 0;
            for(int j = 0; j < res.size(); j++){
                if(res[j] < res[fastfinished]){
                    fastfinished = j;
                }
            }
            
            if(intervals[i].start < res[fastfinished]){
                res.push_back(intervals[i].end);
            }
            else{
                res[fastfinished] = intervals[i].end;
            }
        }
        
        return res.size();
    }
};