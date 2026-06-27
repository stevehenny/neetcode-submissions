class MedianFinder {
    std::priority_queue<int, std::vector<int>, std::less<int>> lessQ;
    std::priority_queue<int, std::vector<int>, std::greater<int>> greaterQ;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lessQ.push(num);
        if(!greaterQ.empty() && lessQ.top() > greaterQ.top()){
            greaterQ.push(lessQ.top());
            lessQ.pop();
        }
        if(lessQ.size() > greaterQ.size() + 1){
            greaterQ.push(lessQ.top());
            lessQ.pop();
        }
        if(greaterQ.size() > lessQ.size() + 1){
            lessQ.push(greaterQ.top());
            greaterQ.pop();
        }
    }
    
    double findMedian() {
        if(lessQ.size() == greaterQ.size()) return static_cast<double>(lessQ.top() + greaterQ.top()) / 2.0;
        else if(lessQ.size() > greaterQ.size()) return static_cast<double>(lessQ.top());
        else return static_cast<double>(greaterQ.top());
    }
};
