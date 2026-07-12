class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // will sort via the first element
        std::sort(intervals.begin(), intervals.end());

        vector<vector<int>> res;
        // print out all intervals after sorting:
        for(int i{}; i < intervals.size(); ++i){
            std::cout << intervals[i][0] << ' ' << intervals[i][1] << '\n';
        }
        
        int n = intervals.size();
        for(int i{0}; i < n; ++i){
            auto& cur_interval = intervals[i];
            while(i < n && cur_interval[1] >= intervals[i][0]){

                cur_interval[0] = std::min(cur_interval[0], intervals[i][0]);
                cur_interval[1] = std::max(cur_interval[1], intervals[i][1]);
                ++i;
              
            }
            res.emplace_back(cur_interval);
            // if no overlap, make sure to back track to make sure we can 
            // start at the ith interval next iteration
            if(i < n && cur_interval[1] < intervals[i][0]){
                --i;
            }
        }
        return res;
    }
};
