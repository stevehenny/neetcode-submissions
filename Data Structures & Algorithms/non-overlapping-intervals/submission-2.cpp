class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count{};
        int n = intervals.size();
        // auto func = 
        std::sort(intervals.begin(), intervals.end());
        int prevEnd = intervals[0][1];
        for(int i{1}; i < n; ++i){
            if(intervals[i][0] >= prevEnd){
                prevEnd = intervals[i][1];
            }
            else{
                prevEnd = std::min(prevEnd, intervals[i][1]);
                ++count;
            }
        }
        
       return count;
      
    }
};
