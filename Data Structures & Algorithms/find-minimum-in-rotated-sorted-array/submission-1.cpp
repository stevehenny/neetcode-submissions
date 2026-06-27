class Solution {
public:
    int findMin(vector<int> &nums) {
        int l{};
        int r = nums.size() - 1;
        int ret_ind{};
        while(l < r){
            int mid = (l + (r - 1)) / 2;
            
            if(nums[mid] < nums[r]){
                r = mid;
                
            }
            else{
                l = mid + 1;
                ret_ind = l;

            }
        


        }
        cout << ret_ind;
        
        return nums[ret_ind];
    }
};
