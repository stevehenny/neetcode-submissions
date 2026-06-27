class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left{};
        int right = heights.size() - 1;
        int ret = INT_MIN;

        while(left < right){
            ret = max(ret, (right -left) * min(heights[left], heights[right]));
            if(heights[right] > heights[left]){
                ++left;
            }
            else{
                --right;
            }

        }
        return ret;
    }
};
