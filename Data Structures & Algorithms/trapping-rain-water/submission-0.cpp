class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max(n);
        vector<int> right_max(n);
        for(int i = 1; i < n; i++){
            right_max[n-i-1] = max(right_max[n-i], height[n-i]);
            left_max[i]= max(left_max[i-1], height[i-1]);
        }

        int ret{};
        for(int i = 0; i < n; i++){
            if(left_max[i] > height[i] && right_max[i] > height[i]){
                ret += (min(left_max[i], right_max[i]) - height[i]);
            }
        }
    
    return ret;
    }
};
