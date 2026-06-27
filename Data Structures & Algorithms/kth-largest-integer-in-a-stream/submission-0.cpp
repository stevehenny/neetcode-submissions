class KthLargest {
std::priority_queue<int, std::vector<int>, std::less<int>> q;
int _k;
public:
    KthLargest(int k, vector<int>& nums) {
        _k = k;
        for(auto num: nums){
            q.push(num);
        }
    }
    
    int add(int val) {
        q.push(val);
        vector<int> popped;
        for(int i = 1; i < _k; ++i){
            popped.push_back(q.top());
            q.pop();
        }
        int ret = q.top();
        for(int i = 0; i < popped.size(); ++i){
            q.push(popped[i]);
        }
        return ret;
    }
};
