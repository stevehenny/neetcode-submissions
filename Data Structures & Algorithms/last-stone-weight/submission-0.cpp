class Solution {
    std::priority_queue<int, std::vector<int>, std::less<int>> q;
public:
    int lastStoneWeight(vector<int>& stones) {
        for(int stone: stones){
            q.push(stone);
        }

        while(q.size() > 1){
            int stone1 = q.top();
            q.pop();
            int stone2 = q.top();
            q.pop();
            if(stone1 == stone2) continue;
            else if(stone1 < stone2){
                stone2 -= stone1;
                q.push(stone2);
            }
            else{
                stone1 -= stone2;
                q.push(stone1);
            }
        }
        return !q.empty() ? q.top() : 0;
    }
};
